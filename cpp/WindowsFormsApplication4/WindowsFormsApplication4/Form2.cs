using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication4
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
       
        static int x = 0, y = 0, w = 20, h = 20, dx = 7, dy = 7;
        private void timer1_Tick(object sender, EventArgs e)
        {
            Graphics p = this.CreateGraphics();
            Pen blackPen = new Pen(Color.Black, 1);
            SolidBrush whiteBrush = new SolidBrush(Color.White);
            p.FillRectangle(whiteBrush, ClientRectangle);
            p.DrawEllipse(blackPen, x, y, w, h);
            x += dx;
            y += dy;
            if ((x + dx) > (this.ClientSize.Width - h)) dx = -dx;
            if ((y + dy) > (this.ClientSize.Height - w)) dy = -dy;
            if (x < 0) dx = -dx;
            if (y < 0) dy = -dy;
        }
    }
}
