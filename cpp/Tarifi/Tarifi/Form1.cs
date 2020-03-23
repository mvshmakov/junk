using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tarifi
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox2.SelectedIndex = comboBox1.SelectedIndex;
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = comboBox2.SelectedIndex;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double result = 0.0;
            switch (comboBox1.SelectedIndex)
            {
                case 0: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
                case 1: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
                case 2: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
                case 3: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
            }
            label5.Text = "\nГород: " + comboBox1.Text +
                          "\nТариф: " + comboBox2.Text +
                          "\nФамилия: " + textBox1.Text +
                          "\nВремя(мин): " + textBox2.Text +
                          "\nРезультат: " + Convert.ToString(result);
        }

        private void расчётToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double result = 0.0;
            switch (comboBox1.SelectedIndex)
            {
                case 0: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
                case 1: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
                case 2: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
                case 3: { result = Convert.ToDouble(textBox2.Text) * Convert.ToDouble(comboBox2.Text); break; }
            }
            label5.Text = "\nГород: " + comboBox1.Text +
                          "\nТариф: " + comboBox2.Text +
                          "\nФамилия: " + textBox1.Text +
                          "\nВремя(мин): " + textBox2.Text +
                          "\nРезультат: " + Convert.ToString(result);
        }
    }
}