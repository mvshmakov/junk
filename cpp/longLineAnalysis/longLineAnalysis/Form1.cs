using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace longLineAnalysis
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e){;}

        private void button1_Click(object sender, EventArgs e)
        {
            int s = 0, sum = 0;
            foreach (int index in checkedListBox1.CheckedIndices)
                s += index;
            foreach (object itemChecked in checkedListBox1.CheckedItems)
                sum += int.Parse(itemChecked.ToString());
        }
    }

    public class Graph
    {
        
    }
}
