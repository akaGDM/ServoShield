using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WinServo
{
    public partial class ServoControl : UserControl
    {
        private int ServoIndex;
        private System.IO.Ports.SerialPort Port;
        private byte[] servo = new byte[100];

        public ServoControl()
        {
            InitializeComponent();
        }

        public void SetIndex(int indx, System.IO.Ports.SerialPort sPort)
        {
            gbServo.Text = "Servo " + indx.ToString();
            pnlServo.Enabled = cbEnabled.Checked;
            ServoSpeed2.Value = 4;
            ServoValue.Value = 1500;
            ServoIndex = indx;
            Port = sPort;
        }

        private void cbEnabled_CheckedChanged(object sender, EventArgs e)
        {
            pnlServo.Enabled = cbEnabled.Checked;
            TransferPacket();
        }

        private void WriteByte(byte value, ref int position)
        {
            if (value == 0x5e) { servo[position++] = 0x5d; servo[position++] = 0x3e; }
            else
                if (value == 0x5d) { servo[position++] = 0x5d; servo[position++] = 0x3d; }
                else servo[position++] = value;
        }

        private int CreatePacket()
        {
            int pos = 0;
            servo[pos++] = 0x5e;
            WriteByte((byte)ServoIndex, ref pos);
            WriteByte((byte)(ServoValue.Value & 0xff), ref pos);
            WriteByte((byte)(ServoValue.Value >> 8), ref pos);
            WriteByte((byte)(ServoSpeed2.Value), ref pos);
            WriteByte((byte)(ServoSpeed1.Value), ref pos);
            WriteByte(Convert.ToByte(cbEnabled.Checked), ref pos);
            servo[pos++] = 0x5e;
            return pos;
        }

        private void TransferPacket()
        {
            int lng = CreatePacket();
            if (Port!=null && Port.IsOpen) Port.Write(servo, 0, lng);
        }

        private void ServoValue_ValueChanged(object sender, EventArgs e)
        {
            TransferPacket();
        }
    }
}
