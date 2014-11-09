namespace WinServo
{
    partial class ServoControl
    {
        /// <summary> 
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором компонентов

        /// <summary> 
        /// Обязательный метод для поддержки конструктора - не изменяйте 
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.gbServo = new System.Windows.Forms.GroupBox();
            this.pnlServo = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.cbEnabled = new System.Windows.Forms.CheckBox();
            this.ServoValue = new System.Windows.Forms.TrackBar();
            this.ServoSpeed1 = new System.Windows.Forms.NumericUpDown();
            this.ServoSpeed2 = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.gbServo.SuspendLayout();
            this.pnlServo.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ServoValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ServoSpeed1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ServoSpeed2)).BeginInit();
            this.SuspendLayout();
            // 
            // gbServo
            // 
            this.gbServo.Controls.Add(this.pnlServo);
            this.gbServo.Controls.Add(this.panel2);
            this.gbServo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gbServo.Location = new System.Drawing.Point(0, 0);
            this.gbServo.Name = "gbServo";
            this.gbServo.Size = new System.Drawing.Size(389, 72);
            this.gbServo.TabIndex = 2;
            this.gbServo.TabStop = false;
            this.gbServo.Text = "groupBox1";
            // 
            // pnlServo
            // 
            this.pnlServo.Controls.Add(this.label2);
            this.pnlServo.Controls.Add(this.label1);
            this.pnlServo.Controls.Add(this.ServoSpeed2);
            this.pnlServo.Controls.Add(this.ServoSpeed1);
            this.pnlServo.Controls.Add(this.ServoValue);
            this.pnlServo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlServo.Location = new System.Drawing.Point(92, 16);
            this.pnlServo.Name = "pnlServo";
            this.pnlServo.Size = new System.Drawing.Size(294, 53);
            this.pnlServo.TabIndex = 1;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.cbEnabled);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel2.Location = new System.Drawing.Point(3, 16);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(89, 53);
            this.panel2.TabIndex = 0;
            // 
            // cbEnabled
            // 
            this.cbEnabled.AutoSize = true;
            this.cbEnabled.Location = new System.Drawing.Point(3, 3);
            this.cbEnabled.Name = "cbEnabled";
            this.cbEnabled.Size = new System.Drawing.Size(65, 17);
            this.cbEnabled.TabIndex = 0;
            this.cbEnabled.Text = "Enabled";
            this.cbEnabled.UseVisualStyleBackColor = true;
            this.cbEnabled.CheckedChanged += new System.EventHandler(this.cbEnabled_CheckedChanged);
            // 
            // ServoValue
            // 
            this.ServoValue.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ServoValue.Location = new System.Drawing.Point(6, 5);
            this.ServoValue.Maximum = 2000;
            this.ServoValue.Minimum = 1000;
            this.ServoValue.Name = "ServoValue";
            this.ServoValue.Size = new System.Drawing.Size(104, 45);
            this.ServoValue.TabIndex = 0;
            this.ServoValue.Value = 1000;
            this.ServoValue.ValueChanged += new System.EventHandler(this.ServoValue_ValueChanged);
            // 
            // ServoSpeed1
            // 
            this.ServoSpeed1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.ServoSpeed1.Location = new System.Drawing.Point(168, 5);
            this.ServoSpeed1.Name = "ServoSpeed1";
            this.ServoSpeed1.Size = new System.Drawing.Size(120, 20);
            this.ServoSpeed1.TabIndex = 1;
            this.ServoSpeed1.ValueChanged += new System.EventHandler(this.ServoValue_ValueChanged);
            // 
            // ServoSpeed2
            // 
            this.ServoSpeed2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.ServoSpeed2.Location = new System.Drawing.Point(168, 31);
            this.ServoSpeed2.Name = "ServoSpeed2";
            this.ServoSpeed2.Size = new System.Drawing.Size(120, 20);
            this.ServoSpeed2.TabIndex = 2;
            this.ServoSpeed2.ValueChanged += new System.EventHandler(this.ServoValue_ValueChanged);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(115, 7);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Speed 1";
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(115, 33);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Speed 2";
            // 
            // ServoControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.gbServo);
            this.Name = "ServoControl";
            this.Size = new System.Drawing.Size(389, 72);
            this.gbServo.ResumeLayout(false);
            this.pnlServo.ResumeLayout(false);
            this.pnlServo.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ServoValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ServoSpeed1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ServoSpeed2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbServo;
        private System.Windows.Forms.Panel pnlServo;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.CheckBox cbEnabled;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown ServoSpeed2;
        private System.Windows.Forms.NumericUpDown ServoSpeed1;
        private System.Windows.Forms.TrackBar ServoValue;
    }
}
