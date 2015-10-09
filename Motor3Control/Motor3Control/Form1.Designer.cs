namespace Motor3Control
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.motor_ctrl3 = new Motor3Control.Motor_ctrl();
            this.motor_ctrl2 = new Motor3Control.Motor_ctrl();
            this.motor_ctrl1 = new Motor3Control.Motor_ctrl();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(534, 10);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 3;
            this.button1.Text = "Refrescar";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(407, 12);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(363, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Puerto";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(363, 39);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(246, 23);
            this.button2.TabIndex = 6;
            this.button2.Text = "Conectar";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // motor_ctrl3
            // 
            this.motor_ctrl3.Location = new System.Drawing.Point(12, 240);
            this.motor_ctrl3.Name = "motor_ctrl3";
            this.motor_ctrl3.Size = new System.Drawing.Size(345, 108);
            this.motor_ctrl3.TabIndex = 2;
            // 
            // motor_ctrl2
            // 
            this.motor_ctrl2.Location = new System.Drawing.Point(12, 126);
            this.motor_ctrl2.Name = "motor_ctrl2";
            this.motor_ctrl2.Size = new System.Drawing.Size(345, 108);
            this.motor_ctrl2.TabIndex = 1;
            // 
            // motor_ctrl1
            // 
            this.motor_ctrl1.Location = new System.Drawing.Point(12, 12);
            this.motor_ctrl1.Name = "motor_ctrl1";
            this.motor_ctrl1.Size = new System.Drawing.Size(345, 108);
            this.motor_ctrl1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(618, 359);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.motor_ctrl3);
            this.Controls.Add(this.motor_ctrl2);
            this.Controls.Add(this.motor_ctrl1);
            this.Name = "Form1";
            this.Text = "Control de Motores";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Motor_ctrl motor_ctrl1;
        private Motor_ctrl motor_ctrl2;
        private Motor_ctrl motor_ctrl3;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button2;
    }
}

