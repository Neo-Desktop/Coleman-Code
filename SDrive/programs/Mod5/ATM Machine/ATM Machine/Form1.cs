using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ATM_Machine
{
    public partial class Form1 : Form
    {
        static Customer customer = new Customer();
        public Form1()
        {
            InitializeComponent();
            InitSQL(); // init the sql side of things
            InitState(); // init our screens
        }

        void InitState() // reinitialize the state
        {
            panel8.Hide(); // hide the confirmation screen
            panel7.Hide(); // hide the deposit screen
            panel6.Hide(); // hide custom withdrawal screen
            panel5.Hide(); // hide insufficient funds screen
            panel4.Hide(); // hide withdrawal screen
            panel3.Hide(); // hide statement screen
            panel2.Hide(); // hide main menu
            label5.Text = "Welcome User"; // dummy text
            panel1.Show(); // show the login screen 

            textBox1.Text = string.Empty; // re-initialize the account id textbox to blank
            textBox2.Text = string.Empty; // re-initialize the pin textbox to blanks

            panel1.Focus(); // Focus.
        }

        void MainMenu()
        {
            panel8.Hide(); // hide the confirmation screen
            panel7.Hide(); // hide the deposit screen
            panel6.Hide(); // hide custom withdrawal screen
            panel5.Hide(); // hide insufficient funds screen
            panel4.Hide(); // hide withdrawal screen
            panel3.Hide(); // hide statement screen

            listBox1.Items.Clear(); // clear the statement listbox
            listBox2.Items.Clear(); // clear the confirmation listbox

            maskedTextBox1.Text = string.Empty; // clear the deposit custom amount field
            maskedTextBox2.Text = string.Empty; // clear the withdrawal custom amount field

            panel2.Show(); // show the main menu
            panel2.Focus(); // focus..

            PopulateTransactions(); // do the transactions
        }

        void InffFunds()
        {
            panel8.Hide(); // hide the confirmation screen
            panel7.Hide(); // hide the deposit screen
            panel6.Hide(); // hide custom withdrawal screen
            panel4.Hide(); // hide withdrawal screen
            panel3.Hide(); // hide statement screen
            panel2.Hide(); // show the main menu
            panel5.Show(); // show insufficient funds screen
            panel5.Focus(); // focus.
        }

        // hackity hack!
        // this property determines which panel is visible
        // based on each panel's visibility property.
        // if statements galore
        public uint visablepanel 
        {
            get
            {
                if (panel8.Visible) // transaction confirm
                {
                    return 8;
                }
                else if (panel7.Visible) // custom deposit
                {
                    return 7;
                }
                else if (panel6.Visible) // custom withdrawal
                {
                    return 6;
                }
                else if (panel5.Visible) // Insufficient Funds
                {
                    return 5;
                }
                else if (panel4.Visible) // Withdrawals
                {
                    return 4;
                }
                else if (panel3.Visible) // balance screen
                {
                    return 3;
                }
                else if (panel2.Visible) // main menu
                {
                    return 2;
                }
                else if (panel1.Visible) // login screen
                {
                    return 1;
                }
                else // or else!
                {
                    return 0;
                }
            }
        }

        private void button1_Click(object sender, EventArgs e) // process the login form
        {
            if (textBox1.Text != string.Empty && textBox2.Text != string.Empty)
            {
                ValidatePin(uint.Parse(textBox1.Text), uint.Parse(textBox2.Text));
                if (customer.AccountNumber > 0) // this is a good value
                {
                    GetCustomerIDFromAccountNumber(customer.AccountNumber);
                    panel1.Hide(); // hide login
                    panel2.Show(); // show main menu
                    panel2.Focus(); // focus.
                    GetCustomerName(customer.CustomerID); // now that we have the customer id, find customer name
                    label5.Text = "Welcome " + customer.Name; // populate header
                    PopulateTransactions(); // populate transactions
                }
                else
                {
                    // show the user an error with direction
                    MessageBox.Show("Invalid Card Number or Pin", "Login failure", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                }
            }
            else
            {
                // show the user an error with direction
                MessageBox.Show("Please enter your Card Number and PIN", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                if (textBox1.Text == string.Empty) // what is empty should be filled
                { // help the user figure out what needs to be corrected
                    textBox1.Focus(); // account number empty
                }
                else if (textBox2.Text == string.Empty)
                {
                    textBox2.Focus(); // pin empty
                }
            }
        }

        private void button5_Click(object sender, EventArgs e) // logoff from the main menu
        {
            InitState();
            // thanks for using bank of biscuit
            MessageBox.Show("You have been successfully logged off. Thanks for using Bank of Biscuit!", "Log-off Notification", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            customer = new Customer();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) // catch the enter button
        {
            if (e.KeyCode == Keys.Enter)
            {
                e.SuppressKeyPress = true;
                //MessageBox.Show("visablepanel = " + visablepanel);
                switch (visablepanel) // what to do based on the currently visible panel
                {
                    case 1:
                        button1.PerformClick();
                        break;
                    case 2:
                        button5.PerformClick();
                        break;
                    case 3:
                        button6.PerformClick();
                        break;
                    case 4:
                        button16.PerformClick();
                        break;
                    case 5:
                        button17.PerformClick();
                        break;
                    case 6:
                        button18.PerformClick();
                        break;
                    case 7:
                        button19.PerformClick();
                        break;
                    case 8:
                        button22.PerformClick();
                        break;
                    default:
                        break;
                }
            }
        }

        private void panel2_Enter(object sender, EventArgs e) // on main menu entrance, focus logoff button
        {
            button5.Focus(); // Focus.
        }

        private void panel1_Enter(object sender, EventArgs e) // on login screen entrance, focus the account number
        {
            textBox1.Focus(); //Focus.
        }

        private void button4_Click(object sender, EventArgs e) // enter to statement screen
        {
            panel2.Hide(); // hide the main menu
            doStatement(); // refresh the statement

            if (customer.balance < 0)
            {
                label8.ForeColor = Color.Red; // in the red?
            }
            else
            {
                label8.ForeColor = Color.Black; // in the black
            }
            label8.Text = customer.balance.ToString("C"); // write out the balance

            panel3.Show(); // show the statement screen 
            panel3.Focus(); // focus.
            button6.Focus(); // now focus again!
        }

        private void button6_Click(object sender, EventArgs e) // mainmenu from statement screen
        {
            MainMenu(); // goto main menu
        }

        private void button2_Click(object sender, EventArgs e) // enter withdraw screen
        {
            panel2.Hide(); // hide main menu
            doStatement(); // update statement

            if (customer.balance < 0)
            {
                label11.ForeColor = Color.Red; // in the red
            }
            else
            {
                label11.ForeColor = Color.Black; // in the black
            }
            label11.Text = customer.balance.ToString("C"); // write out our balance

            panel4.Show(); // show the panel
            panel4.Focus(); // Focus.
            button16.Focus(); // Focus again!
        }

        private void button7_Click(object sender, EventArgs e) // withdraw $20.00
        {
            if (customer.balance > 20)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 20.00M, 'W', DateTime.Now);
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button8_Click(object sender, EventArgs e) // withdraw  $40.00
        {
            if (customer.balance > 40)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 40.00M, 'W', DateTime.Now);
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button9_Click(object sender, EventArgs e) // withdraw  $80.00
        {
            if (customer.balance > 80)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 80.00M, 'W', DateTime.Now); // set the transaction
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button10_Click(object sender, EventArgs e) // withdraw  $100.00
        {
            if (customer.balance > 100)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 100.00M, 'W', DateTime.Now); // set the transaction
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button11_Click(object sender, EventArgs e) // withdraw  $120.00
        {
            if (customer.balance > 120)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 120.00M, 'W', DateTime.Now); // set the transaction
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button12_Click(object sender, EventArgs e) // withdraw  $140.00
        {
            if (customer.balance > 140)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 140.00M, 'W', DateTime.Now); // set the transaction
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button15_Click(object sender, EventArgs e) // withdraw  $180.00
        {
            if (customer.balance > 180)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 180.00M, 'W', DateTime.Now); // set the transaction
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button13_Click(object sender, EventArgs e) // withdraw  $200.00
        {
            if (customer.balance > 200)
            {
                this_transaction = new Transaction(0, customer.AccountNumber, 200.00M, 'W', DateTime.Now); // set the transaction
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
            else // insufficient funds
            {
                InffFunds(); // go there
            }
        }

        private void button14_Click(object sender, EventArgs e) // withdraw enter custom amount
        {
            panel4.Hide(); // hide withdrawals screen
            doStatement(); // update balance
            if (customer.balance < 0)
            {
                label14.ForeColor = Color.Red; // in the red
            }
            else
            {
                label14.ForeColor = Color.Black; // in the black 
            }
            label14.Text = customer.balance.ToString("C"); // write out the balance
            panel6.Show(); // show the panel
            panel6.Focus(); // Focus.
        }

        private void button16_Click(object sender, EventArgs e)// withdraw enter main menu
        {
            this_transaction = null; // clean up the transaction variable
            MainMenu(); // goto main menu
        }

        private void button17_Click(object sender, EventArgs e) // insufficient funds enter main menu
        {
            this_transaction = null; // clean up the transaction variable
            MainMenu(); // goto main menu
        }

        private void button20_Click(object sender, EventArgs e) // main menu from custom withdrawals
        {
            this_transaction = null; // clean up the transaction variable
            MainMenu(); // goto main menu
        }

        private void button18_Click(object sender, EventArgs e) // process custom withdrawal
        {
            if (Convert.ToDecimal(maskedTextBox1.Text.Substring(1)) > customer.balance) // insifficiant funds?
            {
                InffFunds(); // go there
            }
            else
            {
                this_transaction = new Transaction(0, customer.AccountNumber, Convert.ToDecimal(maskedTextBox1.Text.Substring(1)), 'W', DateTime.Now); // set the transaction
                panel6.Hide(); // hide custom withdrawal screen
                panel4.Hide(); // hide withdrawal screen
                panel8.Show(); // show confirmation screen
                panel8.Focus(); // focus.
            }
        }

        private void button22_Click(object sender, EventArgs e) // process transaction from confirmation
        {
            if (InsertTransaction())
            {
                if (this_transaction.type == 'D')
                {   // deposit confirmation
                    MessageBox.Show("A Deposit of " + this_transaction.amount.ToString("C") + " has been posted to your account", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {   // withdrawal confirmation
                    MessageBox.Show("A Withdrawal of " + this_transaction.amount.ToString("C") + " has been posted to your account", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            else
            {   // unspecified error
                MessageBox.Show("We are unable to process your transaction at this time, please try again later", "Termporary Unavailibility", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            MainMenu(); // goto main menu
        }

        private void button21_Click(object sender, EventArgs e) // main menu from confirmation
        {
            MainMenu(); // goto main menu
        }

        private void button3_Click(object sender, EventArgs e) // deposit from mainmenu
        {
            panel2.Hide(); // hide main menu
            doStatement(); // refresh the statement

            if (customer.balance < 0)
            {
                label19.ForeColor = Color.Red; // in the red?
            }
            else
            {
                label19.ForeColor = Color.Black; // in the black
            }
            label19.Text = customer.balance.ToString("C"); // write out the balance

            panel7.Show(); // show deposit screen
            panel7.Focus(); // focus.
        }

        private void button19_Click(object sender, EventArgs e) // process from deposit
        {
            this_transaction = new Transaction(0, customer.AccountNumber, Convert.ToDecimal(maskedTextBox2.Text.Substring(1)), 'D', DateTime.Now); // set the transaction
            panel7.Hide(); // hide custom deposit screen
            panel8.Show(); // show confirmation screen
            panel8.Focus(); // focus.
        }

        private void button23_Click(object sender, EventArgs e) // main menu from deposit
        {
            MainMenu();
        }

        private void panel8_Enter(object sender, EventArgs e) // on focus of the confirmation screen
        {
            if (this_transaction != null)
            {
                string sout = "";
                int padding = 13;
                listBox2.Items.Add(string.Format("{0}|{1}|{2}|{3}|{4}", "Date".PadRight(padding), "Transaction".PadRight(padding), "Withdrawal".PadRight(padding), "Deposit".PadRight(padding), "Balance".PadRight(padding)));
                listBox1.Items.Add("".PadLeft(padding * 5, '-'));
                if (this_transaction.type == 'W')
                {
                    // withdrawal
                    sout = string.Format("{0}|{1}|{2}|{3}|{4}", this_transaction.date.ToShortDateString().PadRight(padding), (customer.CustomerID.ToString().PadLeft(4, '0') + "." + this_transaction.id.ToString().PadLeft(4, '0')).PadRight(padding), this_transaction.amount.ToString("C").PadRight(padding), "".PadRight(padding), customer.balance.ToString("C").PadRight(padding));
                }
                else
                {
                    // deposit
                    sout = string.Format("{0}|{1}|{2}|{3}|{4}", this_transaction.date.ToShortDateString().PadRight(padding), (customer.CustomerID.ToString().PadLeft(4, '0') + "." + this_transaction.id.ToString().PadLeft(4, '0')).PadRight(padding), "".PadRight(padding), this_transaction.amount.ToString("C").PadRight(padding), customer.balance.ToString("C").PadRight(padding));
                }
                listBox2.Items.Add(sout);
            }
            else
            {
                MessageBox.Show("A Null transaction?!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                MainMenu();
            }
            button22.Focus(); // focus the process button
        }

        private void panel7_Enter(object sender, EventArgs e) // on entrance of deposit
        {
            maskedTextBox2.Focus(); // Focus.
        }

        private void maskedTextBox2_MaskInputRejected(object sender, MaskInputRejectedEventArgs e) // move to process button on full input box
        {
            if (maskedTextBox2.MaskFull)
            {
                button19.Focus(); // Focus.
            }
        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e) // move to process button on full input box
        {
            if (maskedTextBox1.MaskFull)
            {
                button18.Focus(); // Focus.
            }
        }

        private void panel5_Enter(object sender, EventArgs e) // on entrance of insufficiant funds
        {
            button17.Focus(); // focus the main menu button
        }

        private void panel6_Enter(object sender, EventArgs e) // on entrance of custom withdrawal
        {
            maskedTextBox1.Focus(); // focus the input box
        }

    }
}
