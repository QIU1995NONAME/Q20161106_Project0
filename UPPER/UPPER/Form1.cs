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
        public delegate void InterfaceHandle(byte[] byteattay);
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
                // 如果命令长度不足5 说明有问题
                if (command.Length < 5)
                {
                    // FIXME
                    return;
                }
                int time_second = 0;
                time_second += command[1];
                time_second += command[2] << 8;
                time_second += command[3] << 16;
                time_second += command[4] << 24;
                status_stm32_systime.Text = "STM: "+ new DateTime(0).AddYears(1969).AddSeconds(time_second).ToString("yyyy/MM/dd HH:mm:ss");
                // 后面准备编写关于对各种状态的解析
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
            }
        }

        private void btn_test_Click(object sender, EventArgs e)
        {
            RTGraphGenerator imggen = new RTGraphGenerator();
            imggen.GraphWidth = pic_test.Width;
            imggen.GraphHeight = pic_test.Height;
            imggen.AxisRangeX = 1000;
            Dictionary<long, double> testdata = new Dictionary<long, double>();
            testdata.Add(0, -2.521707246);
            testdata.Add(50, -1.310526213);
            testdata.Add(100, 2.869743589);
            testdata.Add(150, -1.767411005);
            testdata.Add(200, -0.152919848);
            testdata.Add(250, 0.780624748);
            testdata.Add(300, 3.776620546);
            testdata.Add(350, -1.246947845);
            testdata.Add(400, 3.327629995);
            testdata.Add(450, 0.788862252);
            testdata.Add(500, 1.837697798);
            testdata.Add(550, 1.298368614);
            testdata.Add(600, 1.687328307);
            testdata.Add(650, -1.670196629);
            testdata.Add(700, -0.013712272);
            testdata.Add(750, 3.142558117);
            testdata.Add(800, -1.08552826);
            testdata.Add(850, 2.973618267);
            testdata.Add(900, 2.15371096);
            testdata.Add(950, -0.3853369);
            testdata.Add(1000, 3.738113823);


            pic_test.Image = imggen.generateImage(testdata);

            // SerialMessage.analyze_msg(new byte[]{0x05,0xEE ,0x77 ,0x1A ,0x7C});
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
    }
}
