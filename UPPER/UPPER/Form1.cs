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
                    // serial_execute_command(SerialMessage.analyze_msg(serial_cmd.ToArray()));
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

        private void btn_heartbeat_Click(object sender, EventArgs e)
        {
            // 启动心跳
            serial1_send_0x77();
        }
        private void serial_execute_command(byte[] command)
        {
            if (command == null)
            {
                // FIXME 没有相应的处理办法
                return;
            }
            // 心跳消息 四个字节的秒信息 两个字节的毫秒信息
            if (command[0] == 0x77)
            {
                // 回送一个心跳
                serial1_send_0x77();
                // 如果命令长度不足7 说明有问题
                if (command.Length < 7)
                {
                    // FIXME
                    return;
                }
                int time_second = 0;
                time_second += command[1];
                time_second += command[2] << 8;
                time_second += command[3] << 16;
                time_second += command[4] << 24;
                status2.Text = "STM: "+ new DateTime(0).AddYears(1969).AddSeconds(time_second).ToString("yyyy/MM/dd HH:mm:ss");
            }
        }

        private void btn_test_Click(object sender, EventArgs e)
        {
            // SerialMessage.analyze_msg(new byte[]{0x05,0xEE ,0x77 ,0x1A ,0x7C});
        }
    }
}
