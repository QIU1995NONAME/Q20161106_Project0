using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.Win32;

using System.Diagnostics;
namespace UPPER
{
    public partial class Form1 : Form
    {
        private Dictionary<long, double> dict_angle_pulse = new Dictionary<long, double>();
        private Dictionary<long, double> dict_angle_degree = new Dictionary<long, double>();
        private Dictionary<long, double> dict_fan_level = new Dictionary<long, double>();
        private Dictionary<long, double> dict_fan_percent = new Dictionary<long, double>();
        private Dictionary<long, double> dict_step_step = new Dictionary<long, double>();
        private Dictionary<long, double> dict_step_degree = new Dictionary<long, double>();
        private byte[] stm32_status = new byte[4];
        public delegate void InterfaceHandle(byte[] byteattay);

        private void analyze_status()
        {
            // Byte 0 Bit 6 SD 卡是否可用
            if (((stm32_status[0]) & (1 << 6)) != 0)
            {
                lbl_status_sd.Text = "Enabled";
                lbl_status_sd.BackColor = Color.LightGreen;
            }
            else {
                lbl_status_sd.Text = "Disabled";
                lbl_status_sd.BackColor = Color.FromArgb(0xEE,0x90,0x90);
            }
            // Byte 0 Bit 5 底层采样是否正在进行
            if (((stm32_status[0]) & (1 << 5)) != 0)
            {
                lbl_status_sampling.Text = "Running";
                lbl_status_sampling.BackColor = Color.LightGreen;
                btn_sampling_start.Enabled = false;
                btn_sampling_stop.Enabled = true;
            }
            else
            {
                lbl_status_sampling.Text = "Stopped";
                lbl_status_sampling.BackColor = Color.FromArgb(0xEE, 0x90, 0x90);
                btn_sampling_start.Enabled = true;
                btn_sampling_stop.Enabled = false;
            }
            // Byte 0 Bit 4 串口采样是否正在进行
            if (((stm32_status[0]) & (1 << 4)) != 0)
            {
                lbl_status_senddata.Text = "Running";
                lbl_status_senddata.BackColor = Color.LightGreen;
                btn_senddata_start.Enabled = false;
                btn_senddata_stop.Enabled = true;
            }
            else
            {
                lbl_status_senddata.Text = "Stopped";
                lbl_status_senddata.BackColor = Color.FromArgb(0xEE, 0x90, 0x90);
                btn_senddata_start.Enabled = true;
                btn_senddata_stop.Enabled = false;
            }
        }
        public Form1()
        {
            InitializeComponent();
        }
        // 获取本机时间 并显示到状态栏
        private void change_local_time()
        {
            status_label_systime.Text = "LOCAL: " + DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss");
        }
        // 定时功能
        // 定时刷新状态栏的本机时间
        private void timer1_Tick(object sender, EventArgs e)
        {
            change_local_time();
        }
        // 载入窗体
        private void Form1_Load(object sender, EventArgs e)
        {
            change_local_time();
        }
        // 发送心跳数据
        private void serial1_send_0x77()
        {
            if (!serial1.IsOpen)
            {
                // TODO 如果串口处于关闭状态
                return;
            }
            byte[] msg = SerialMessage.pack_msg(new byte[] { 0x77 });
            serial1.Write(msg, 0, msg.Length);
        }
        // 发送时间同步数据
        private void serial1_send_0x78() {
            byte[] msg = new byte[5];
            msg[0] = 0x78;
            DateTime dt = DateTime.Now;
            long ticks = dt.AddYears(-1969).Ticks;
            ticks /= 10000000;//转换到Unix秒时间戳
            msg[1] = (byte)(ticks & 0xFF);
            ticks >>= 8;
            msg[2] = (byte)(ticks & 0xFF);
            ticks >>= 8;
            msg[3] = (byte)(ticks & 0xFF);
            ticks >>= 8;
            msg[4] = (byte)(ticks & 0xFF);
            // 打包并发送
            byte[] pack = SerialMessage.pack_msg(msg);
            serial1.Write(pack, 0, pack.Length);
        }
        // 底层采样功能停止
        private void serial1_send_0x60()
        {
            if (!serial1.IsOpen)
            {
                return;
            }
            byte[] msg = SerialMessage.pack_msg(new byte[] { 0x60 });
            serial1.Write(msg, 0, msg.Length);
        }
        // 底层采样功能启动
        private void serial1_send_0x61()
        {
            if (!serial1.IsOpen)
            {
                return;
            }
            byte[] msg = SerialMessage.pack_msg(new byte[] { 0x61 });
            serial1.Write(msg, 0, msg.Length);
        }
        // 串口采样功能停止
        private void serial1_send_0x68()
        {
            if (!serial1.IsOpen)
            {
                return;
            }
            byte[] msg = SerialMessage.pack_msg(new byte[] { 0x68 });
            serial1.Write(msg, 0, msg.Length);
        }
        // 串口采样功能启动
        private void serial1_send_0x69()
        {
            if (!serial1.IsOpen)
            {
                return;
            }
            byte[] msg = SerialMessage.pack_msg(new byte[] { 0x69 });
            serial1.Write(msg, 0, msg.Length);
        }
        private void btn_refresh_Click(object sender, EventArgs e)
        {
            // 其实可用的串口这种东西是可以在注册表里面找到的
            // WINDOWS本身就掌管着这个电脑上面所有的硬件，不是么？
            // 它自己一定会想得很周全，所以就不必我们再去扫描了。
            RegistryKey key_comm = Registry.LocalMachine.OpenSubKey(@"Hardware\DeviceMap\SerialComm");
            // 首先先把下拉菜单清空
            combo_comm.Items.Clear();
            if (key_comm != null)
            {
                // 获取变量名
                string[] key_comm_keynames = key_comm.GetValueNames();
                foreach (string keyname in key_comm_keynames)
                {
                    this.combo_comm.Items.Add((string)(key_comm.GetValue(keyname)));
                }
            }
        }
        private void btn_connect_Click(object sender, EventArgs e)
        {
            // 失效控件
            btn_refresh.Enabled = false;
            combo_comm.Enabled = false;
            btn_connect.Enabled = false;
            // 获取串口字符串
            string str_port = (string)(combo_comm.SelectedItem);
            // 设置串口属性
            serial1.BaudRate = 57600;
            try
            {
                serial1.PortName = str_port;
                serial1.Open();
            }
            catch
            {
                // DO NOTHING
            }
            if (serial1.IsOpen)
            {
                // 打开成功
                btn_disconnect.Enabled = true;
            }
            else
            {
                btn_refresh.Enabled = true;
                combo_comm.Enabled = true;
                btn_connect.Enabled = true;
                MessageBox.Show(String.Format("打开串口 \"{0}\" 失败！", str_port));
            }
        }

        private void btn_disconnect_Click(object sender, EventArgs e)
        {
            serial1.Close();
            if (!serial1.IsOpen)
            {
                btn_refresh.Enabled = true;
                combo_comm.Enabled = true;
                btn_connect.Enabled = true;
                btn_disconnect.Enabled = false;
            }
        }
        private bool serial_cmd_is_receive = false;// 是否处于接收命令状态
        private bool serial_cmd_is_escape = false;// 是否处于转义状态
        private LinkedList<byte> serial_cmd = new LinkedList<byte>();
        private void serial1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            // 如果还有没有读取的缓冲区字符
            while (serial1.BytesToRead > 0)
            {
                byte b = (byte)serial1.ReadByte();
                // DEBUG
                // Debug.Print("{0} ", serial1.ReadByte());
                
                // 如果没有处于接收状态
                if (!serial_cmd_is_receive)
                {
                    if (b == SerialMessage.MSG_STTC)
                    {
                        serial_cmd_is_receive = true;
                        serial_cmd_is_escape = false;
                    }
                    continue;
                }
                // (接收状态中) 如果处于转义中
                if (serial_cmd_is_escape)
                {
                    // 直接将数据放入List
                    serial_cmd.AddLast(b);
                    serial_cmd_is_escape = false;
                    continue;
                }
                // (接收状态中，无转义)如果接收到结束字符或者转义字符
                if (b == SerialMessage.MSG_ENDC)
                {
                    // 处理数据
                    InterfaceHandle interfaceUpdateHandle = new InterfaceHandle(serial_execute_command);
                    this.Invoke(interfaceUpdateHandle, new object[] { SerialMessage.analyze_msg(serial_cmd.ToArray()) });
                    // SerialMessage.analyze_msg(serial_cmd.ToArray());
                    // 清空
                    serial_cmd.Clear();
                    serial_cmd_is_receive = false;
                    serial_cmd_is_escape = false;
                    continue;
                }
                if (b == SerialMessage.MSG_ESCC)
                {
                    serial_cmd_is_escape = true;
                    continue;
                }
                // (接收状态 无转义 不是特殊字符)
                serial_cmd.AddLast(b);
                
            }
        }
        private void serial_execute_command(byte[] command)
        {
            if (command == null)
            {
                // FIXME 没有相应的处理办法
                return;
            }
            // 心跳消息
            if (command[0] == 0x77)
            {
                // 回送一个心跳
                serial1_send_0x77();
                // 如果命令长度不足9 说明有问题
                if (command.Length < 9)
                {
                    // FIXME
                    return;
                }
                int time_second = 0;
                time_second |= command[1];
                time_second |= command[2] << 8;
                time_second |= command[3] << 16;
                time_second |= command[4] << 24;
                status_stm32_systime.Text = "STM: "+ new DateTime(0).AddYears(1969).AddSeconds(time_second).ToString("yyyy/MM/dd HH:mm:ss");
                // 获取各种状态
                stm32_status[0] = command[5];
                stm32_status[1] = command[6];
                stm32_status[2] = command[7];
                stm32_status[3] = command[8];
                // 做出反应
                analyze_status();
            }
            // 采样消息
            else if (command[0] == 0x69)
            {
                // 如果命令长度不足17 说明有问题
                if (command.Length < 17)
                {
                    // FIXME
                    return;
                }
                // 分析数据并保存
                // 秒
                long time_ms = 0;
                int tmpi = 0;
                double tmpd = 0;
                // 有可能存在负值 统一的处理方式
                // 秒
                tmpi |= command[4];
                tmpi <<= 8;
                tmpi |= command[3];
                tmpi <<= 8;
                tmpi |= command[2];
                tmpi <<= 8;
                tmpi |= command[1];
                time_ms = tmpi * 1000;
                // 毫秒
                tmpi = 0;
                tmpi |= command[6];
                tmpi <<= 8;
                tmpi |= command[5];
                time_ms += tmpi;
                // 是否存在这个时间点
                if (dict_angle_pulse.ContainsKey(time_ms)) {
                    return;
                }
                // 光电编码器值
                tmpi = 0;
                tmpi |= command[12];
                tmpi <<= 8;
                tmpi |= command[11];
                tmpi <<= 8;
                tmpi |= command[10];
                tmpi <<= 8;
                tmpi |= command[9];
                // 转成角度
                tmpd = 360.0 * tmpi / 1000;
                // 存入内存
                dict_angle_pulse.Add(time_ms,tmpi);
                dict_angle_degree.Add(time_ms, tmpd);
                // 获取风扇转速
                tmpi = 0;
                tmpi |= command[8];
                tmpi <<= 8;
                tmpi |= command[7];
                // 转换成百分比
                tmpd = 100.0 * tmpi / 1800;
                // 存入内存
                dict_fan_level.Add(time_ms, tmpi);
                dict_fan_percent.Add(time_ms, tmpd);
                // 获取步进电机数据
                tmpi = 0;
                tmpi |= command[16];
                tmpi <<= 8;
                tmpi |= command[15];
                tmpi <<= 8;
                tmpi |= command[14];
                tmpi <<= 8;
                tmpi |= command[13];
                // 转换为角度
                tmpd = 360.0 * tmpi / 3200;
                dict_step_step.Add(time_ms, tmpi);
                dict_step_degree.Add(time_ms, tmpd);
                // 绘制曲线
                pic_draw_graphs();
            }
        }
        // 绘制曲线图
        private void pic_draw_graphs()
        {
            RTGraphGenerator imggen = new RTGraphGenerator();
            int axis_x_range = track_chg_range.Value;
            switch (axis_x_range)
            {
                case 0: // 1s
                    axis_x_range = 1000;
                    break;
                case 1: // 2s
                    axis_x_range = 2000; 
                    break;
                case 2: // 5s
                    axis_x_range = 5000;
                    break;
                case 3: // 10s
                    axis_x_range = 10000;
                    break;
                case 4: // 30s
                    axis_x_range = 30000;
                    break;
                case 5: // 60s
                    axis_x_range = 60000;
                    break;
                case 6: // 120s
                    axis_x_range = 120000;
                    break;
                default: // 300s
                    axis_x_range = 300000;
                    break;
            }
            imggen.AxisRangeX = axis_x_range;
            imggen.GraphWidth = pic_angle_pulse.Width;
            imggen.GraphHeight = pic_angle_pulse.Height;
            imggen.ForeColor = Color.Cyan;
            pic_angle_pulse.Image = imggen.generateImage(dict_angle_pulse);
            imggen.GraphWidth = pic_angle_degree.Width;
            imggen.GraphHeight = pic_angle_degree.Height;
            imggen.ForeColor = Color.LightCyan;
            pic_angle_degree.Image = imggen.generateImage(dict_angle_degree);
            imggen.GraphWidth = pic_fan_level.Width;
            imggen.GraphHeight = pic_fan_level.Height;
            imggen.ForeColor = Color.Yellow;
            pic_fan_level.Image = imggen.generateImage(dict_fan_level);
            imggen.GraphWidth = pic_fan_level_percent.Width;
            imggen.GraphHeight = pic_fan_level_percent.Height;
            imggen.ForeColor = Color.LightYellow;
            pic_fan_level_percent.Image = imggen.generateImage(dict_fan_percent);
            imggen.GraphWidth = pic_step_step.Width;
            imggen.GraphHeight = pic_step_step.Height;
            imggen.ForeColor = Color.GreenYellow;
            pic_step_step.Image = imggen.generateImage(dict_step_step);
            imggen.GraphWidth = pic_step_degree.Width;
            imggen.GraphHeight = pic_step_degree.Height;
            imggen.ForeColor = Color.LightGreen;
            pic_step_degree.Image = imggen.generateImage(dict_step_degree);
        }
        private void menu_item_timesync_Click(object sender, EventArgs e)
        {
            // 时间同步
            serial1_send_0x78();
        }

        private void menu_item_heartbeat_Click(object sender, EventArgs e)
        {
            // 启动心跳
            serial1_send_0x77();
        }

        private void btn_sampling_start_Click(object sender, EventArgs e)
        {
            btn_sampling_start.Enabled = false;
            serial1_send_0x61();
        }

        private void btn_sampling_stop_Click(object sender, EventArgs e)
        {
            btn_sampling_stop.Enabled = false;
            serial1_send_0x60();
        }

        private void btn_senddata_start_Click(object sender, EventArgs e)
        {
            btn_senddata_start.Enabled = false;
            serial1_send_0x69();
        }

        private void btn_senddata_stop_Click(object sender, EventArgs e)
        {
            btn_senddata_stop.Enabled = false;
            serial1_send_0x68();
        }
    }
}
