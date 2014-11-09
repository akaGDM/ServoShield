using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WinServo
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        ServoControl[] servos = new ServoControl[20];
        private void frmMain_Load(object sender, EventArgs e)
        {
            cbPort.Items.Clear();
            cbPort.Items.AddRange(System.IO.Ports.SerialPort.GetPortNames());
            if (cbPort.Items.Count > 0) cbPort.SelectedIndex = 0;
            for (int i = 0; i < 20; i++)
            {
                servos[i] = new ServoControl();
                servos[i].Location = new System.Drawing.Point(0, servos[i].Height * i);
                servos[i].Width = panel2.ClientRectangle.Width;
                servos[i].Parent = panel2;
                servos[i].SetIndex(i, serialPort);
                
            }
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (cbPort.Enabled)
            {
                serialPort.Close();
                serialPort.PortName = cbPort.SelectedItem.ToString();
                serialPort.Open();
                cbPort.Enabled = !serialPort.IsOpen;
            }
            else
            {
                serialPort.Close();
                cbPort.Enabled = !serialPort.IsOpen;
            }
        }

        private void serialPort_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            //string str = serialPort.ReadExisting();
//            textBox1.AppendText(str);
        }

        
    }
}
