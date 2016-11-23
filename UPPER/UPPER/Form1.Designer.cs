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
            this.btn_timesync = new System.Windows.Forms.Button();
            this.btn_test = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.track_chg_range = new System.Windows.Forms.TrackBar();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.pic_angle_pulse = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
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
            this.flowLayoutPanel1.Controls.Add(this.btn_timesync);
            this.flowLayoutPanel1.Controls.Add(this.btn_test);
            this.flowLayoutPanel1.Controls.Add(this.label6);
            this.flowLayoutPanel1.Controls.Add(this.track_chg_range);
            this.flowLayoutPanel1.Controls.Add(this.button2);
            this.flowLayoutPanel1.Controls.Add(this.button3);
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
            // btn_timesync
            // 
            this.btn_timesync.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_timesync.Enabled = false;
            this.btn_timesync.Location = new System.Drawing.Point(0, 115);
            this.btn_timesync.Margin = new System.Windows.Forms.Padding(0);
            this.btn_timesync.Name = "btn_timesync";
            this.btn_timesync.Size = new System.Drawing.Size(93, 31);
            this.btn_timesync.TabIndex = 9;
            this.btn_timesync.Text = "断开";
            this.btn_timesync.UseVisualStyleBackColor = true;
            // 
            // btn_test
            // 
            this.btn_test.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_test.Location = new System.Drawing.Point(0, 146);
            this.btn_test.Margin = new System.Windows.Forms.Padding(0);
            this.btn_test.Name = "btn_test";
            this.btn_test.Size = new System.Drawing.Size(93, 31);
            this.btn_test.TabIndex = 3;
            this.btn_test.Text = "TEST";
            this.btn_test.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("宋体", 7.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label6.Location = new System.Drawing.Point(3, 177);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(85, 10);
            this.label6.TabIndex = 8;
            this.label6.Text = "曲线图横坐标范围";
            // 
            // track_chg_range
            // 
            this.track_chg_range.LargeChange = 1;
            this.track_chg_range.Location = new System.Drawing.Point(3, 190);
            this.track_chg_range.Maximum = 6;
            this.track_chg_range.Name = "track_chg_range";
            this.track_chg_range.Size = new System.Drawing.Size(83, 42);
            this.track_chg_range.TabIndex = 7;
            // 
            // button2
            // 
            this.button2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.button2.Enabled = false;
            this.button2.Location = new System.Drawing.Point(0, 235);
            this.button2.Margin = new System.Windows.Forms.Padding(0);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(93, 31);
            this.button2.TabIndex = 10;
            this.button2.Text = "断开";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this.button3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.button3.Enabled = false;
            this.button3.Location = new System.Drawing.Point(0, 266);
            this.button3.Margin = new System.Windows.Forms.Padding(0);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(93, 31);
            this.button3.TabIndex = 11;
            this.button3.Text = "断开";
            this.button3.UseVisualStyleBackColor = true;
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
            this.tabPage1.Location = new System.Drawing.Point(4, 26);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(907, 493);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "下位机状态";
            this.tabPage1.UseVisualStyleBackColor = true;
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
        private System.Windows.Forms.Button btn_test;
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
        private System.Windows.Forms.Button btn_timesync;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
    }
}

