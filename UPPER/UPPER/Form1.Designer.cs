namespace UPPER
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menu1 = new System.Windows.Forms.MenuStrip();
            this.menu_opt_Operate = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_heartbeat = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_item_timesync = new System.Windows.Forms.ToolStripMenuItem();
            this.status1 = new System.Windows.Forms.StatusStrip();
            this.status_label_systime = new System.Windows.Forms.ToolStripStatusLabel();
            this.status_stm32_systime = new System.Windows.Forms.ToolStripStatusLabel();
            this.serial1 = new System.IO.Ports.SerialPort(this.components);
            this.combo_comm = new System.Windows.Forms.ComboBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.btn_refresh = new System.Windows.Forms.Button();
            this.btn_connect = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.btn_disconnect = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.track_chg_range = new System.Windows.Forms.TrackBar();
            this.btn_sampling_stop = new System.Windows.Forms.Button();
            this.pic_angle_pulse = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.txt_dbl_2 = new System.Windows.Forms.TextBox();
            this.txt_dbl_1 = new System.Windows.Forms.TextBox();
            this.txt_dbl_0 = new System.Windows.Forms.TextBox();
            this.txt_int_1 = new System.Windows.Forms.TextBox();
            this.txt_int_0 = new System.Windows.Forms.TextBox();
            this.txt_mode = new System.Windows.Forms.TextBox();
            this.txt_pj = new System.Windows.Forms.TextBox();
            this.lbl_mode = new System.Windows.Forms.Label();
            this.lbl_pj = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.label21 = new System.Windows.Forms.Label();
            this.label19 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.lbl_dbl_2 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.lbl_dbl_1 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.lbl_dbl_0 = new System.Windows.Forms.Label();
            this.lbl_status_senddata = new System.Windows.Forms.Label();
            this.lbl_int_1 = new System.Windows.Forms.Label();
            this.lbl_status_sampling = new System.Windows.Forms.Label();
            this.lbl_int_0 = new System.Windows.Forms.Label();
            this.lbl_status_sd = new System.Windows.Forms.Label();
            this.btn_set_dbl_2 = new System.Windows.Forms.Button();
            this.btn_senddata_start = new System.Windows.Forms.Button();
            this.btn_set_dbl_1 = new System.Windows.Forms.Button();
            this.btn_set_mode = new System.Windows.Forms.Button();
            this.btn_set_dbl_0 = new System.Windows.Forms.Button();
            this.btn_set_pj = new System.Windows.Forms.Button();
            this.btn_set_int_1 = new System.Windows.Forms.Button();
            this.btn_senddata_stop = new System.Windows.Forms.Button();
            this.btn_set_int_0 = new System.Windows.Forms.Button();
            this.btn_sampling_start = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.pic_step_degree = new System.Windows.Forms.PictureBox();
            this.pic_step_step = new System.Windows.Forms.PictureBox();
            this.pic_fan_level_percent = new System.Windows.Forms.PictureBox();
            this.pic_angle_degree = new System.Windows.Forms.PictureBox();
            this.pic_fan_level = new System.Windows.Forms.PictureBox();
            this.menu1.SuspendLayout();
            this.status1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.track_chg_range)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_angle_pulse)).BeginInit();
            this.panel2.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pic_step_degree)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_step_step)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_fan_level_percent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_angle_degree)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_fan_level)).BeginInit();
            this.SuspendLayout();
            // 
            // menu1
            // 
            this.menu1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_opt_Operate});
            this.menu1.Location = new System.Drawing.Point(0, 0);
            this.menu1.Name = "menu1";
            this.menu1.Padding = new System.Windows.Forms.Padding(8, 3, 0, 3);
            this.menu1.Size = new System.Drawing.Size(1016, 24);
            this.menu1.TabIndex = 0;
            // 
            // menu_opt_Operate
            // 
            this.menu_opt_Operate.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_item_heartbeat,
            this.menu_item_timesync});
            this.menu_opt_Operate.Name = "menu_opt_Operate";
            this.menu_opt_Operate.Size = new System.Drawing.Size(59, 18);
            this.menu_opt_Operate.Text = "&Operate";
            // 
            // menu_item_heartbeat
            // 
            this.menu_item_heartbeat.Name = "menu_item_heartbeat";
            this.menu_item_heartbeat.Size = new System.Drawing.Size(118, 22);
            this.menu_item_heartbeat.Text = "启动心跳";
            this.menu_item_heartbeat.Click += new System.EventHandler(this.menu_item_heartbeat_Click);
            // 
            // menu_item_timesync
            // 
            this.menu_item_timesync.Name = "menu_item_timesync";
            this.menu_item_timesync.Size = new System.Drawing.Size(118, 22);
            this.menu_item_timesync.Text = "时间同步";
            this.menu_item_timesync.Click += new System.EventHandler(this.menu_item_timesync_Click);
            // 
            // status1
            // 
            this.status1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.status_label_systime,
            this.status_stm32_systime});
            this.status1.Location = new System.Drawing.Point(0, 551);
            this.status1.Name = "status1";
            this.status1.Padding = new System.Windows.Forms.Padding(1, 0, 19, 0);
            this.status1.Size = new System.Drawing.Size(1016, 22);
            this.status1.TabIndex = 1;
            // 
            // status_label_systime
            // 
            this.status_label_systime.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.status_label_systime.BorderStyle = System.Windows.Forms.Border3DStyle.SunkenInner;
            this.status_label_systime.Name = "status_label_systime";
            this.status_label_systime.Size = new System.Drawing.Size(165, 17);
            this.status_label_systime.Text = "LOCAL: yyyy/MM/dd HH:mm:ss";
            // 
            // status_stm32_systime
            // 
            this.status_stm32_systime.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.status_stm32_systime.BorderStyle = System.Windows.Forms.Border3DStyle.SunkenInner;
            this.status_stm32_systime.Name = "status_stm32_systime";
            this.status_stm32_systime.Size = new System.Drawing.Size(153, 17);
            this.status_stm32_systime.Text = "STM: yyyy/MM/dd HH:mm:ss";
            // 
            // serial1
            // 
            this.serial1.BaudRate = 57600;
            this.serial1.PortName = "COM3";
            this.serial1.ReadTimeout = 10000;
            this.serial1.WriteTimeout = 10000;
            this.serial1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serial1_DataReceived);
            // 
            // combo_comm
            // 
            this.combo_comm.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.combo_comm.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combo_comm.FormattingEnabled = true;
            this.combo_comm.Location = new System.Drawing.Point(0, 29);
            this.combo_comm.Margin = new System.Windows.Forms.Padding(0);
            this.combo_comm.Name = "combo_comm";
            this.combo_comm.Size = new System.Drawing.Size(93, 24);
            this.combo_comm.TabIndex = 1;
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // btn_refresh
            // 
            this.btn_refresh.Location = new System.Drawing.Point(0, 0);
            this.btn_refresh.Margin = new System.Windows.Forms.Padding(0);
            this.btn_refresh.Name = "btn_refresh";
            this.btn_refresh.Size = new System.Drawing.Size(93, 29);
            this.btn_refresh.TabIndex = 0;
            this.btn_refresh.Text = "刷新串口";
            this.btn_refresh.UseVisualStyleBackColor = true;
            this.btn_refresh.Click += new System.EventHandler(this.btn_refresh_Click);
            // 
            // btn_connect
            // 
            this.btn_connect.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_connect.Location = new System.Drawing.Point(0, 53);
            this.btn_connect.Margin = new System.Windows.Forms.Padding(0);
            this.btn_connect.Name = "btn_connect";
            this.btn_connect.Size = new System.Drawing.Size(93, 31);
            this.btn_connect.TabIndex = 2;
            this.btn_connect.Text = "连接";
            this.btn_connect.UseVisualStyleBackColor = true;
            this.btn_connect.Click += new System.EventHandler(this.btn_connect_Click);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.flowLayoutPanel1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 24);
            this.panel1.Margin = new System.Windows.Forms.Padding(4);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(97, 527);
            this.panel1.TabIndex = 5;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.btn_refresh);
            this.flowLayoutPanel1.Controls.Add(this.combo_comm);
            this.flowLayoutPanel1.Controls.Add(this.btn_connect);
            this.flowLayoutPanel1.Controls.Add(this.btn_disconnect);
            this.flowLayoutPanel1.Controls.Add(this.label6);
            this.flowLayoutPanel1.Controls.Add(this.track_chg_range);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel1.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.flowLayoutPanel1.Margin = new System.Windows.Forms.Padding(0);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(93, 523);
            this.flowLayoutPanel1.TabIndex = 4;
            // 
            // btn_disconnect
            // 
            this.btn_disconnect.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_disconnect.Enabled = false;
            this.btn_disconnect.Location = new System.Drawing.Point(0, 84);
            this.btn_disconnect.Margin = new System.Windows.Forms.Padding(0);
            this.btn_disconnect.Name = "btn_disconnect";
            this.btn_disconnect.Size = new System.Drawing.Size(93, 31);
            this.btn_disconnect.TabIndex = 3;
            this.btn_disconnect.Text = "断开";
            this.btn_disconnect.UseVisualStyleBackColor = true;
            this.btn_disconnect.Click += new System.EventHandler(this.btn_disconnect_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("宋体", 7.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label6.Location = new System.Drawing.Point(3, 115);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(85, 10);
            this.label6.TabIndex = 8;
            this.label6.Text = "曲线图横坐标范围";
            // 
            // track_chg_range
            // 
            this.track_chg_range.LargeChange = 1;
            this.track_chg_range.Location = new System.Drawing.Point(3, 128);
            this.track_chg_range.Maximum = 6;
            this.track_chg_range.Name = "track_chg_range";
            this.track_chg_range.Size = new System.Drawing.Size(83, 42);
            this.track_chg_range.TabIndex = 4;
            // 
            // btn_sampling_stop
            // 
            this.btn_sampling_stop.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_sampling_stop.Enabled = false;
            this.btn_sampling_stop.Location = new System.Drawing.Point(4, 131);
            this.btn_sampling_stop.Margin = new System.Windows.Forms.Padding(0);
            this.btn_sampling_stop.Name = "btn_sampling_stop";
            this.btn_sampling_stop.Size = new System.Drawing.Size(298, 31);
            this.btn_sampling_stop.TabIndex = 7;
            this.btn_sampling_stop.Text = "停止底层采样";
            this.btn_sampling_stop.UseVisualStyleBackColor = true;
            this.btn_sampling_stop.Click += new System.EventHandler(this.btn_sampling_stop_Click);
            // 
            // pic_angle_pulse
            // 
            this.pic_angle_pulse.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pic_angle_pulse.Location = new System.Drawing.Point(0, 49);
            this.pic_angle_pulse.Name = "pic_angle_pulse";
            this.pic_angle_pulse.Size = new System.Drawing.Size(286, 207);
            this.pic_angle_pulse.TabIndex = 6;
            this.pic_angle_pulse.TabStop = false;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.tabControl1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel2.Location = new System.Drawing.Point(97, 24);
            this.panel2.Margin = new System.Windows.Forms.Padding(6);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(919, 527);
            this.panel2.TabIndex = 7;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(915, 523);
            this.tabControl1.TabIndex = 7;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.txt_dbl_2);
            this.tabPage1.Controls.Add(this.txt_dbl_1);
            this.tabPage1.Controls.Add(this.txt_dbl_0);
            this.tabPage1.Controls.Add(this.txt_int_1);
            this.tabPage1.Controls.Add(this.txt_int_0);
            this.tabPage1.Controls.Add(this.txt_mode);
            this.tabPage1.Controls.Add(this.txt_pj);
            this.tabPage1.Controls.Add(this.lbl_mode);
            this.tabPage1.Controls.Add(this.lbl_pj);
            this.tabPage1.Controls.Add(this.label12);
            this.tabPage1.Controls.Add(this.label14);
            this.tabPage1.Controls.Add(this.label9);
            this.tabPage1.Controls.Add(this.label11);
            this.tabPage1.Controls.Add(this.label10);
            this.tabPage1.Controls.Add(this.label23);
            this.tabPage1.Controls.Add(this.label21);
            this.tabPage1.Controls.Add(this.label19);
            this.tabPage1.Controls.Add(this.label17);
            this.tabPage1.Controls.Add(this.lbl_dbl_2);
            this.tabPage1.Controls.Add(this.label13);
            this.tabPage1.Controls.Add(this.lbl_dbl_1);
            this.tabPage1.Controls.Add(this.label8);
            this.tabPage1.Controls.Add(this.lbl_dbl_0);
            this.tabPage1.Controls.Add(this.lbl_status_senddata);
            this.tabPage1.Controls.Add(this.lbl_int_1);
            this.tabPage1.Controls.Add(this.lbl_status_sampling);
            this.tabPage1.Controls.Add(this.lbl_int_0);
            this.tabPage1.Controls.Add(this.lbl_status_sd);
            this.tabPage1.Controls.Add(this.btn_set_dbl_2);
            this.tabPage1.Controls.Add(this.btn_senddata_start);
            this.tabPage1.Controls.Add(this.btn_set_dbl_1);
            this.tabPage1.Controls.Add(this.btn_set_mode);
            this.tabPage1.Controls.Add(this.btn_set_dbl_0);
            this.tabPage1.Controls.Add(this.btn_set_pj);
            this.tabPage1.Controls.Add(this.btn_set_int_1);
            this.tabPage1.Controls.Add(this.btn_senddata_stop);
            this.tabPage1.Controls.Add(this.btn_set_int_0);
            this.tabPage1.Controls.Add(this.btn_sampling_start);
            this.tabPage1.Controls.Add(this.btn_sampling_stop);
            this.tabPage1.Location = new System.Drawing.Point(4, 26);
            this.tabPage1.Margin = new System.Windows.Forms.Padding(0);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Size = new System.Drawing.Size(907, 493);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "下位机状态及控制";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // txt_dbl_2
            // 
            this.txt_dbl_2.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txt_dbl_2.Location = new System.Drawing.Point(617, 115);
            this.txt_dbl_2.Name = "txt_dbl_2";
            this.txt_dbl_2.Size = new System.Drawing.Size(129, 26);
            this.txt_dbl_2.TabIndex = 12;
            // 
            // txt_dbl_1
            // 
            this.txt_dbl_1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txt_dbl_1.Location = new System.Drawing.Point(617, 87);
            this.txt_dbl_1.Name = "txt_dbl_1";
            this.txt_dbl_1.Size = new System.Drawing.Size(129, 26);
            this.txt_dbl_1.TabIndex = 12;
            // 
            // txt_dbl_0
            // 
            this.txt_dbl_0.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txt_dbl_0.Location = new System.Drawing.Point(617, 59);
            this.txt_dbl_0.Name = "txt_dbl_0";
            this.txt_dbl_0.Size = new System.Drawing.Size(129, 26);
            this.txt_dbl_0.TabIndex = 12;
            // 
            // txt_int_1
            // 
            this.txt_int_1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txt_int_1.Location = new System.Drawing.Point(617, 32);
            this.txt_int_1.Name = "txt_int_1";
            this.txt_int_1.Size = new System.Drawing.Size(129, 26);
            this.txt_int_1.TabIndex = 12;
            // 
            // txt_int_0
            // 
            this.txt_int_0.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txt_int_0.Location = new System.Drawing.Point(617, 4);
            this.txt_int_0.Name = "txt_int_0";
            this.txt_int_0.Size = new System.Drawing.Size(129, 26);
            this.txt_int_0.TabIndex = 12;
            // 
            // txt_mode
            // 
            this.txt_mode.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txt_mode.Location = new System.Drawing.Point(151, 412);
            this.txt_mode.Name = "txt_mode";
            this.txt_mode.Size = new System.Drawing.Size(149, 38);
            this.txt_mode.TabIndex = 12;
            // 
            // txt_pj
            // 
            this.txt_pj.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txt_pj.Location = new System.Drawing.Point(2, 412);
            this.txt_pj.Name = "txt_pj";
            this.txt_pj.Size = new System.Drawing.Size(149, 38);
            this.txt_pj.TabIndex = 12;
            // 
            // lbl_mode
            // 
            this.lbl_mode.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_mode.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_mode.Location = new System.Drawing.Point(151, 378);
            this.lbl_mode.Name = "lbl_mode";
            this.lbl_mode.Size = new System.Drawing.Size(151, 29);
            this.lbl_mode.TabIndex = 11;
            this.lbl_mode.Text = "MD_NO";
            // 
            // lbl_pj
            // 
            this.lbl_pj.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_pj.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_pj.Location = new System.Drawing.Point(3, 378);
            this.lbl_pj.Name = "lbl_pj";
            this.lbl_pj.Size = new System.Drawing.Size(150, 29);
            this.lbl_pj.TabIndex = 11;
            this.lbl_pj.Text = "PJ_NO";
            // 
            // label12
            // 
            this.label12.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label12.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label12.Location = new System.Drawing.Point(151, 347);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(151, 29);
            this.label12.TabIndex = 11;
            this.label12.Text = "当前模式";
            // 
            // label14
            // 
            this.label14.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label14.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label14.Location = new System.Drawing.Point(4, 224);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(298, 123);
            this.label14.TabIndex = 11;
            this.label14.Text = "工程0 停止\r\n工程1 帆版风扇 模式: 0 手动, 1 自动;\r\n工程2 步进电机\r\n";
            // 
            // label9
            // 
            this.label9.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label9.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label9.Location = new System.Drawing.Point(3, 347);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(150, 29);
            this.label9.TabIndex = 11;
            this.label9.Text = "当前工程";
            // 
            // label11
            // 
            this.label11.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label11.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label11.Location = new System.Drawing.Point(3, 66);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(156, 31);
            this.label11.TabIndex = 11;
            this.label11.Text = "串口采样:";
            this.label11.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label10
            // 
            this.label10.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label10.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label10.Location = new System.Drawing.Point(3, 35);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(156, 31);
            this.label10.TabIndex = 11;
            this.label10.Text = "底层采样:";
            this.label10.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label23
            // 
            this.label23.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label23.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label23.Location = new System.Drawing.Point(329, 114);
            this.label23.Name = "label23";
            this.label23.Size = new System.Drawing.Size(133, 23);
            this.label23.TabIndex = 11;
            this.label23.Text = "KD值:";
            this.label23.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label21
            // 
            this.label21.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label21.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label21.Location = new System.Drawing.Point(329, 86);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(133, 23);
            this.label21.TabIndex = 11;
            this.label21.Text = "1/KI值:";
            this.label21.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label19
            // 
            this.label19.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label19.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label19.Location = new System.Drawing.Point(329, 58);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(133, 23);
            this.label19.TabIndex = 11;
            this.label19.Text = "KP值:";
            this.label19.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label17
            // 
            this.label17.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label17.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label17.Location = new System.Drawing.Point(329, 31);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(133, 23);
            this.label17.TabIndex = 11;
            this.label17.Text = "角度脉冲值:";
            this.label17.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // lbl_dbl_2
            // 
            this.lbl_dbl_2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_dbl_2.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_dbl_2.Location = new System.Drawing.Point(468, 114);
            this.lbl_dbl_2.Name = "lbl_dbl_2";
            this.lbl_dbl_2.Size = new System.Drawing.Size(143, 23);
            this.lbl_dbl_2.TabIndex = 11;
            this.lbl_dbl_2.Text = "XXXXXXXX";
            // 
            // label13
            // 
            this.label13.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label13.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label13.Location = new System.Drawing.Point(329, 3);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(133, 23);
            this.label13.TabIndex = 11;
            this.label13.Text = "风扇设定值:";
            this.label13.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // lbl_dbl_1
            // 
            this.lbl_dbl_1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_dbl_1.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_dbl_1.Location = new System.Drawing.Point(468, 86);
            this.lbl_dbl_1.Name = "lbl_dbl_1";
            this.lbl_dbl_1.Size = new System.Drawing.Size(143, 23);
            this.lbl_dbl_1.TabIndex = 11;
            this.lbl_dbl_1.Text = "XXXXXXXX";
            // 
            // label8
            // 
            this.label8.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label8.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label8.Location = new System.Drawing.Point(3, 4);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(156, 31);
            this.label8.TabIndex = 11;
            this.label8.Text = "SD卡:";
            this.label8.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // lbl_dbl_0
            // 
            this.lbl_dbl_0.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_dbl_0.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_dbl_0.Location = new System.Drawing.Point(468, 58);
            this.lbl_dbl_0.Name = "lbl_dbl_0";
            this.lbl_dbl_0.Size = new System.Drawing.Size(143, 23);
            this.lbl_dbl_0.TabIndex = 11;
            this.lbl_dbl_0.Text = "XXXXXXXX";
            // 
            // lbl_status_senddata
            // 
            this.lbl_status_senddata.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_status_senddata.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_status_senddata.Location = new System.Drawing.Point(159, 66);
            this.lbl_status_senddata.Name = "lbl_status_senddata";
            this.lbl_status_senddata.Size = new System.Drawing.Size(143, 31);
            this.lbl_status_senddata.TabIndex = 11;
            this.lbl_status_senddata.Text = "XXXXXXXX";
            // 
            // lbl_int_1
            // 
            this.lbl_int_1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_int_1.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_int_1.Location = new System.Drawing.Point(468, 31);
            this.lbl_int_1.Name = "lbl_int_1";
            this.lbl_int_1.Size = new System.Drawing.Size(143, 23);
            this.lbl_int_1.TabIndex = 11;
            this.lbl_int_1.Text = "XXXXXXXX";
            // 
            // lbl_status_sampling
            // 
            this.lbl_status_sampling.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_status_sampling.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_status_sampling.Location = new System.Drawing.Point(159, 35);
            this.lbl_status_sampling.Name = "lbl_status_sampling";
            this.lbl_status_sampling.Size = new System.Drawing.Size(143, 31);
            this.lbl_status_sampling.TabIndex = 11;
            this.lbl_status_sampling.Text = "XXXXXXXX";
            // 
            // lbl_int_0
            // 
            this.lbl_int_0.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_int_0.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_int_0.Location = new System.Drawing.Point(468, 3);
            this.lbl_int_0.Name = "lbl_int_0";
            this.lbl_int_0.Size = new System.Drawing.Size(143, 23);
            this.lbl_int_0.TabIndex = 11;
            this.lbl_int_0.Text = "XXXXXXXX";
            // 
            // lbl_status_sd
            // 
            this.lbl_status_sd.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbl_status_sd.Font = new System.Drawing.Font("宋体", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_status_sd.Location = new System.Drawing.Point(159, 4);
            this.lbl_status_sd.Name = "lbl_status_sd";
            this.lbl_status_sd.Size = new System.Drawing.Size(143, 31);
            this.lbl_status_sd.TabIndex = 11;
            this.lbl_status_sd.Text = "XXXXXXXX";
            // 
            // btn_set_dbl_2
            // 
            this.btn_set_dbl_2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_set_dbl_2.Location = new System.Drawing.Point(749, 114);
            this.btn_set_dbl_2.Margin = new System.Windows.Forms.Padding(0);
            this.btn_set_dbl_2.Name = "btn_set_dbl_2";
            this.btn_set_dbl_2.Size = new System.Drawing.Size(93, 28);
            this.btn_set_dbl_2.TabIndex = 6;
            this.btn_set_dbl_2.Text = "应用修改";
            this.btn_set_dbl_2.UseVisualStyleBackColor = true;
            // 
            // btn_senddata_start
            // 
            this.btn_senddata_start.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_senddata_start.Enabled = false;
            this.btn_senddata_start.Location = new System.Drawing.Point(4, 162);
            this.btn_senddata_start.Margin = new System.Windows.Forms.Padding(0);
            this.btn_senddata_start.Name = "btn_senddata_start";
            this.btn_senddata_start.Size = new System.Drawing.Size(298, 31);
            this.btn_senddata_start.TabIndex = 8;
            this.btn_senddata_start.Text = "启动串口采集数据";
            this.btn_senddata_start.UseVisualStyleBackColor = true;
            this.btn_senddata_start.Click += new System.EventHandler(this.btn_senddata_start_Click);
            // 
            // btn_set_dbl_1
            // 
            this.btn_set_dbl_1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_set_dbl_1.Location = new System.Drawing.Point(749, 86);
            this.btn_set_dbl_1.Margin = new System.Windows.Forms.Padding(0);
            this.btn_set_dbl_1.Name = "btn_set_dbl_1";
            this.btn_set_dbl_1.Size = new System.Drawing.Size(93, 28);
            this.btn_set_dbl_1.TabIndex = 6;
            this.btn_set_dbl_1.Text = "应用修改";
            this.btn_set_dbl_1.UseVisualStyleBackColor = true;
            // 
            // btn_set_mode
            // 
            this.btn_set_mode.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_set_mode.Location = new System.Drawing.Point(153, 453);
            this.btn_set_mode.Margin = new System.Windows.Forms.Padding(0);
            this.btn_set_mode.Name = "btn_set_mode";
            this.btn_set_mode.Size = new System.Drawing.Size(149, 29);
            this.btn_set_mode.TabIndex = 9;
            this.btn_set_mode.Text = "设定当前模式";
            this.btn_set_mode.UseVisualStyleBackColor = true;
            this.btn_set_mode.Click += new System.EventHandler(this.btn_set_mode_Click);
            // 
            // btn_set_dbl_0
            // 
            this.btn_set_dbl_0.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_set_dbl_0.Location = new System.Drawing.Point(749, 58);
            this.btn_set_dbl_0.Margin = new System.Windows.Forms.Padding(0);
            this.btn_set_dbl_0.Name = "btn_set_dbl_0";
            this.btn_set_dbl_0.Size = new System.Drawing.Size(93, 28);
            this.btn_set_dbl_0.TabIndex = 6;
            this.btn_set_dbl_0.Text = "应用修改";
            this.btn_set_dbl_0.UseVisualStyleBackColor = true;
            // 
            // btn_set_pj
            // 
            this.btn_set_pj.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_set_pj.Location = new System.Drawing.Point(4, 453);
            this.btn_set_pj.Margin = new System.Windows.Forms.Padding(0);
            this.btn_set_pj.Name = "btn_set_pj";
            this.btn_set_pj.Size = new System.Drawing.Size(149, 29);
            this.btn_set_pj.TabIndex = 9;
            this.btn_set_pj.Text = "设定当前工程";
            this.btn_set_pj.UseVisualStyleBackColor = true;
            this.btn_set_pj.Click += new System.EventHandler(this.btn_set_pj_Click);
            // 
            // btn_set_int_1
            // 
            this.btn_set_int_1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_set_int_1.Location = new System.Drawing.Point(749, 31);
            this.btn_set_int_1.Margin = new System.Windows.Forms.Padding(0);
            this.btn_set_int_1.Name = "btn_set_int_1";
            this.btn_set_int_1.Size = new System.Drawing.Size(93, 28);
            this.btn_set_int_1.TabIndex = 6;
            this.btn_set_int_1.Text = "应用修改";
            this.btn_set_int_1.UseVisualStyleBackColor = true;
            // 
            // btn_senddata_stop
            // 
            this.btn_senddata_stop.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_senddata_stop.Enabled = false;
            this.btn_senddata_stop.Location = new System.Drawing.Point(4, 193);
            this.btn_senddata_stop.Margin = new System.Windows.Forms.Padding(0);
            this.btn_senddata_stop.Name = "btn_senddata_stop";
            this.btn_senddata_stop.Size = new System.Drawing.Size(298, 31);
            this.btn_senddata_stop.TabIndex = 9;
            this.btn_senddata_stop.Text = "停止串口采集数据";
            this.btn_senddata_stop.UseVisualStyleBackColor = true;
            this.btn_senddata_stop.Click += new System.EventHandler(this.btn_senddata_stop_Click);
            // 
            // btn_set_int_0
            // 
            this.btn_set_int_0.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_set_int_0.Location = new System.Drawing.Point(749, 3);
            this.btn_set_int_0.Margin = new System.Windows.Forms.Padding(0);
            this.btn_set_int_0.Name = "btn_set_int_0";
            this.btn_set_int_0.Size = new System.Drawing.Size(93, 28);
            this.btn_set_int_0.TabIndex = 6;
            this.btn_set_int_0.Text = "应用修改";
            this.btn_set_int_0.UseVisualStyleBackColor = true;
            // 
            // btn_sampling_start
            // 
            this.btn_sampling_start.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_sampling_start.Enabled = false;
            this.btn_sampling_start.Location = new System.Drawing.Point(4, 100);
            this.btn_sampling_start.Margin = new System.Windows.Forms.Padding(0);
            this.btn_sampling_start.Name = "btn_sampling_start";
            this.btn_sampling_start.Size = new System.Drawing.Size(298, 31);
            this.btn_sampling_start.TabIndex = 6;
            this.btn_sampling_start.Text = "启动底层采样";
            this.btn_sampling_start.UseVisualStyleBackColor = true;
            this.btn_sampling_start.Click += new System.EventHandler(this.btn_sampling_start_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.label2);
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.label1);
            this.tabPage2.Controls.Add(this.pic_step_degree);
            this.tabPage2.Controls.Add(this.pic_step_step);
            this.tabPage2.Controls.Add(this.pic_fan_level_percent);
            this.tabPage2.Controls.Add(this.pic_angle_degree);
            this.tabPage2.Controls.Add(this.pic_fan_level);
            this.tabPage2.Controls.Add(this.pic_angle_pulse);
            this.tabPage2.Location = new System.Drawing.Point(4, 26);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(907, 492);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "曲线图";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.Location = new System.Drawing.Point(1, 259);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(224, 16);
            this.label2.TabIndex = 8;
            this.label2.Text = "Angle Degree 光电编码器角度";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label4.Location = new System.Drawing.Point(289, 259);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(216, 16);
            this.label4.TabIndex = 8;
            this.label4.Text = "Fan Level % 风扇转速百分比";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label7.Location = new System.Drawing.Point(581, 259);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(240, 16);
            this.label7.TabIndex = 8;
            this.label7.Text = "StepMotor Degree 步进电机角度";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label5.Location = new System.Drawing.Point(581, 29);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(224, 16);
            this.label5.TabIndex = 8;
            this.label5.Text = "StepMotor Step 步进电机计步";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label3.Location = new System.Drawing.Point(289, 27);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(184, 16);
            this.label3.TabIndex = 8;
            this.label3.Text = "Fan Level 风扇转速等级";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(1, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(248, 16);
            this.label1.TabIndex = 8;
            this.label1.Text = "Angle Pulse 光电编码器脉冲计数";
            // 
            // pic_step_degree
            // 
            this.pic_step_degree.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pic_step_degree.Location = new System.Drawing.Point(584, 286);
            this.pic_step_degree.Name = "pic_step_degree";
            this.pic_step_degree.Size = new System.Drawing.Size(286, 207);
            this.pic_step_degree.TabIndex = 6;
            this.pic_step_degree.TabStop = false;
            // 
            // pic_step_step
            // 
            this.pic_step_step.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pic_step_step.Location = new System.Drawing.Point(584, 49);
            this.pic_step_step.Name = "pic_step_step";
            this.pic_step_step.Size = new System.Drawing.Size(286, 207);
            this.pic_step_step.TabIndex = 6;
            this.pic_step_step.TabStop = false;
            // 
            // pic_fan_level_percent
            // 
            this.pic_fan_level_percent.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pic_fan_level_percent.Location = new System.Drawing.Point(292, 286);
            this.pic_fan_level_percent.Name = "pic_fan_level_percent";
            this.pic_fan_level_percent.Size = new System.Drawing.Size(286, 207);
            this.pic_fan_level_percent.TabIndex = 6;
            this.pic_fan_level_percent.TabStop = false;
            // 
            // pic_angle_degree
            // 
            this.pic_angle_degree.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pic_angle_degree.Location = new System.Drawing.Point(0, 286);
            this.pic_angle_degree.Name = "pic_angle_degree";
            this.pic_angle_degree.Size = new System.Drawing.Size(286, 207);
            this.pic_angle_degree.TabIndex = 6;
            this.pic_angle_degree.TabStop = false;
            // 
            // pic_fan_level
            // 
            this.pic_fan_level.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pic_fan_level.Location = new System.Drawing.Point(292, 49);
            this.pic_fan_level.Name = "pic_fan_level";
            this.pic_fan_level.Size = new System.Drawing.Size(286, 207);
            this.pic_fan_level.TabIndex = 6;
            this.pic_fan_level.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1016, 573);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.status1);
            this.Controls.Add(this.menu1);
            this.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.MainMenuStrip = this.menu1;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MinimumSize = new System.Drawing.Size(1024, 600);
            this.Name = "Form1";
            this.Text = "Project0";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menu1.ResumeLayout(false);
            this.menu1.PerformLayout();
            this.status1.ResumeLayout(false);
            this.status1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.track_chg_range)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_angle_pulse)).EndInit();
            this.panel2.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pic_step_degree)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_step_step)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_fan_level_percent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_angle_degree)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_fan_level)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menu1;
        private System.Windows.Forms.StatusStrip status1;
        private System.IO.Ports.SerialPort serial1;
        private System.Windows.Forms.ComboBox combo_comm;
        private System.Windows.Forms.ToolStripStatusLabel status_label_systime;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button btn_refresh;
        private System.Windows.Forms.Button btn_connect;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btn_disconnect;
        private System.Windows.Forms.ToolStripStatusLabel status_stm32_systime;
        private System.Windows.Forms.ToolStripMenuItem menu_opt_Operate;
        private System.Windows.Forms.ToolStripMenuItem menu_item_timesync;
        private System.Windows.Forms.ToolStripMenuItem menu_item_heartbeat;
        private System.Windows.Forms.PictureBox pic_angle_pulse;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.PictureBox pic_step_degree;
        private System.Windows.Forms.PictureBox pic_step_step;
        private System.Windows.Forms.PictureBox pic_fan_level_percent;
        private System.Windows.Forms.PictureBox pic_angle_degree;
        private System.Windows.Forms.PictureBox pic_fan_level;
        private System.Windows.Forms.TrackBar track_chg_range;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btn_sampling_stop;
        private System.Windows.Forms.Button btn_sampling_start;
        private System.Windows.Forms.Button btn_senddata_start;
        private System.Windows.Forms.Button btn_senddata_stop;
        private System.Windows.Forms.Label lbl_status_sd;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label lbl_status_sampling;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label lbl_status_senddata;
        private System.Windows.Forms.Label lbl_mode;
        private System.Windows.Forms.Label lbl_pj;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txt_mode;
        private System.Windows.Forms.TextBox txt_pj;
        private System.Windows.Forms.Button btn_set_mode;
        private System.Windows.Forms.Button btn_set_pj;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label lbl_int_0;
        private System.Windows.Forms.TextBox txt_int_0;
        private System.Windows.Forms.TextBox txt_dbl_2;
        private System.Windows.Forms.TextBox txt_dbl_1;
        private System.Windows.Forms.TextBox txt_dbl_0;
        private System.Windows.Forms.TextBox txt_int_1;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label lbl_dbl_2;
        private System.Windows.Forms.Label lbl_dbl_1;
        private System.Windows.Forms.Label lbl_dbl_0;
        private System.Windows.Forms.Label lbl_int_1;
        private System.Windows.Forms.Button btn_set_dbl_2;
        private System.Windows.Forms.Button btn_set_dbl_1;
        private System.Windows.Forms.Button btn_set_dbl_0;
        private System.Windows.Forms.Button btn_set_int_1;
        private System.Windows.Forms.Button btn_set_int_0;
    }
}

