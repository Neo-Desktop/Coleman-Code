using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WinForms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            if (!SQLInit())
            {
                textBox1.Enabled = false;
                radioButton1.Enabled = false; radioButton2.Enabled = false;
                listBox1.Enabled = false;
                button1.Enabled = false;
            }
            else
            {
                InitControls();
            }
        }

        public void InitControls()
        {
            listBox1.Items.Clear();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            if (!textBox1.Text.Equals(String.Empty))
            {
                int id = Convert.ToInt32(this.textBox1.Text);
                string acctType = "";

                if (radioButton1.Checked)
                {
                    acctType = "C";
                }
                else
                {
                    acctType = "S";
                }
                label4.Text = GetCustomerName(id);
                label5.Text = GetAccountNumber(id, acctType);
                PopulateListBox(label5.Text);
            }
            else
            {
                MessageBox.Show("Please enter a customer number", "No Customer number");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
