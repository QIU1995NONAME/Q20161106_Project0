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
            this.status1 = new System.Windows.Forms.StatusStrip();
            this.status_label_systime = new System.Windows.Forms.ToolStripStatusLabel();
            this.serial1 = new System.IO.Ports.SerialPort(this.components);
            this.combo_comm = new System.Windows.Forms.ComboBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.btn_refresh = new System.Windows.Forms.Button();
            this.btn_connect = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btn_heartbeat = new System.Windows.Forms.Button();
            this.btn_disconnect = new System.Windows.Forms.Button();
            this.status1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menu1
            // 
            this.menu1.Location = new System.Drawing.Point(0, 0);
            this.menu1.Name = "menu1";
            this.menu1.Padding = new System.Windows.Forms.Padding(8, 3, 0, 3);
            this.menu1.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.menu1.Size = new System.Drawing.Size(632, 24);
            this.menu1.TabIndex = 0;
            // 
            // status1
            // 
            this.status1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.status_label_systime});
            this.status1.Location = new System.Drawing.Point(0, 431);
            this.status1.Name = "status1";
            this.status1.Padding = new System.Windows.Forms.Padding(1, 0, 19, 0);
            this.status1.Size = new System.Drawing.Size(632, 22);
            this.status1.TabIndex = 1;
            // 
            // status_label_systime
            // 
            this.status_label_systime.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.status_label_systime.Name = "status_label_systime";
            this.status_label_systime.Size = new System.Drawing.Size(165, 17);
            this.status_label_systime.Text = "LOCAL: yyyy/MM/dd HH:mm:ss";
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
            this.combo_comm.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combo_comm.FormattingEnabled = true;
            this.combo_comm.Location = new System.Drawing.Point(0, 43);
            this.combo_comm.Margin = new System.Windows.Forms.Padding(4);
            this.combo_comm.Name = "combo_comm";
            this.combo_comm.Size = new System.Drawing.Size(113, 24);
            this.combo_comm.TabIndex = 2;
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // btn_refresh
            // 
            this.btn_refresh.Location = new System.Drawing.Point(0, 4);
            this.btn_refresh.Margin = new System.Windows.Forms.Padding(4);
            this.btn_refresh.Name = "btn_refresh";
            this.btn_refresh.Size = new System.Drawing.Size(118, 31);
            this.btn_refresh.TabIndex = 3;
            this.btn_refresh.Text = "刷新串口";
            this.btn_refresh.UseVisualStyleBackColor = true;
            this.btn_refresh.Click += new System.EventHandler(this.btn_refresh_Click);
            // 
            // btn_connect
            // 
            this.btn_connect.Location = new System.Drawing.Point(0, 75);
            this.btn_connect.Margin = new System.Windows.Forms.Padding(4);
            this.btn_connect.Name = "btn_connect";
            this.btn_connect.Size = new System.Drawing.Size(53, 31);
            this.btn_connect.TabIndex = 4;
            this.btn_connect.Text = "连接";
            this.btn_connect.UseVisualStyleBackColor = true;
            this.btn_connect.Click += new System.EventHandler(this.btn_connect_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.btn_heartbeat);
            this.panel1.Controls.Add(this.btn_refresh);
            this.panel1.Controls.Add(this.btn_disconnect);
            this.panel1.Controls.Add(this.btn_connect);
            this.panel1.Controls.Add(this.combo_comm);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 24);
            this.panel1.Margin = new System.Windows.Forms.Padding(4);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(128, 407);
            this.panel1.TabIndex = 5;
            // 
            // btn_heartbeat
            // 
            this.btn_heartbeat.Location = new System.Drawing.Point(0, 113);
            this.btn_heartbeat.Name = "btn_heartbeat";
            this.btn_heartbeat.Size = new System.Drawing.Size(118, 28);
            this.btn_heartbeat.TabIndex = 5;
            this.btn_heartbeat.Text = "启动心跳";
            this.btn_heartbeat.UseVisualStyleBackColor = true;
            this.btn_heartbeat.Click += new System.EventHandler(this.btn_heartbeat_Click);
            // 
            // btn_disconnect
            // 
            this.btn_disconnect.Enabled = false;
            this.btn_disconnect.Location = new System.Drawing.Point(65, 75);
            this.btn_disconnect.Margin = new System.Windows.Forms.Padding(4);
            this.btn_disconnect.Name = "btn_disconnect";
            this.btn_disconnect.Size = new System.Drawing.Size(53, 31);
            this.btn_disconnect.TabIndex = 4;
            this.btn_disconnect.Text = "断开";
            this.btn_disconnect.UseVisualStyleBackColor = true;
            this.btn_disconnect.Click += new System.EventHandler(this.btn_disconnect_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(632, 453);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.status1);
            this.Controls.Add(this.menu1);
            this.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.MainMenuStrip = this.menu1;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MinimumSize = new System.Drawing.Size(640, 480);
            this.Name = "Form1";
            this.Text = "Project0";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.status1.ResumeLayout(false);
            this.status1.PerformLayout();
            this.panel1.ResumeLayout(false);
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
        private System.Windows.Forms.Button btn_heartbeat;
    }
}

