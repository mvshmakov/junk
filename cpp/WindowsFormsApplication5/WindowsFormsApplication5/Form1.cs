using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void справкаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Random r = new Random();
            int x = r.Next(ClientSize.Width), y = r.Next(ClientSize.Height),
                w = r.Next(10, 30), h = w;
            Graphics gr = this.CreateGraphics();
            Pen pen1 = new Pen(Color.FromArgb(r.Next(255), r.Next(255), r.Next(255), r.Next(255)), r.Next(0, 10));
            gr.DrawEllipse(pen1, x, y, w, h);
            progressBar1.Value++;
            if (progressBar1.Value == progressBar1.Maximum) progressBar1.Value = progressBar1.Minimum;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.ShowDialog();
        }

        private void нарисоватьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            timer1.Start();
            Random r = new Random();
            int x = r.Next(ClientSize.Width), y = r.Next(ClientSize.Height),
                w = r.Next(10, 30), h = w;
            Graphics gr = this.CreateGraphics();
            Pen pen1 = new Pen(Color.FromArgb(r.Next(255), r.Next(255), r.Next(255), r.Next(255)), r.Next(0, 10));
            gr.DrawEllipse(pen1, x, y, w, h);
            progressBar1.Value++;
            if (progressBar1.Value == progressBar1.Maximum) progressBar1.Value = progressBar1.Minimum;
        }
    }
}
