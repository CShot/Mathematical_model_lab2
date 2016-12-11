using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
           // if(openFileDialog1.ShowDialog()==DialogResult.OK)
            //{
                StreamReader streamReader = new StreamReader("result.txt");
                int X = 1;
                while(!streamReader.EndOfStream)
                {
                    int y = Convert.ToInt16(streamReader.ReadLine());
                    chart1.Series[0].Points.AddXY(X, y);
                    X++;
                }
                streamReader.Close();
            //}
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
    }
}
