using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Drawing;

namespace ATM_Machine
{
    public partial class Form1
    {
        public static SqlConnection connection;
        public static Transaction this_transaction;
        public bool InitSQL()
        {
            connection = new SqlConnection((string)(new SqlCredential("172.16.2.34", "db77260", "daeddb98", "db77260")).ToString());
            if (SQLReady())
            {
                toolStripStatusLabel1.Text = "Connected";
                return true;
            }
            else
            {
                toolStripStatusLabel1.Text = "Not connected";
                MessageBox.Show("Error - unable to access server. Please try again later.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                button1.Enabled = false;
                return false;
            }
        }

        public bool SQLReady()
        {
            if (connection == null) { return false; }
            try
            {
                connection.Open();
                var canOpen = connection.State == ConnectionState.Open;
                connection.Close();
                return canOpen;
            }
            catch
            {
                return false;
            }
        }

        public bool ConnIsOpen()
        {
            var canOpen = connection.State == ConnectionState.Open;
            return canOpen;
        }

        public uint ValidatePin(uint cardnum, uint pin)
        {
            SqlCommand sql = new SqlCommand(@"SELECT * FROM ATMCard_t WHERE (card_number = " + cardnum + " AND pin = " + pin + ") "+
                "OR (account_number = " + cardnum + " AND pin = " + pin + ")", connection);
            object[] values = new object[4];
            if (!ConnIsOpen())
            {
                connection.Open();
            }
            if (ConnIsOpen())
            {
                try
                {
                    //value = Convert.ToDecimal(sql.ExecuteScalar());
                    SqlDataReader reader = sql.ExecuteReader();
                    reader.Read();
                    reader.GetValues(values); // grab the first row returned
                }
                catch (Exception ex)
                {
                    StackTrace st = new StackTrace(new StackFrame(true));
                    StackFrame sf = st.GetFrame(0);
                    new ErrorThrower(sf, ex.Message);
                }
                finally
                {
                    if (ConnIsOpen())
                    {
                        connection.Close();
                    }
                }
                if (values[0] != null) // populate the customer object
                {
                    customer.ATMNumber = Convert.ToUInt32((int)values[0]);
                    customer.AccountNumber = Convert.ToUInt32((decimal)values[1]);
                    customer.PIN = Convert.ToUInt32((string)values[2]);
                    return Convert.ToUInt32((decimal)values[1]);
                }
            }
            return 0;
        }

        public uint GetCustomerIDFromAccountNumber(uint accountnum)
        {
            SqlCommand sql = new SqlCommand(@"SELECT customer_id FROM accounts_t WHERE account_number = " + accountnum, connection);
            string value = string.Empty;
            if (!ConnIsOpen())
            {
                connection.Open();
            }
            try
            {
                value = sql.ExecuteScalar().ToString();
            }
            catch (Exception ex)
            {
                StackTrace st = new StackTrace(new StackFrame(true));
                StackFrame sf = st.GetFrame(0);
                new ErrorThrower(sf, ex.Message);
            }
            finally
            {
                if (ConnIsOpen())
                {
                    connection.Close();
                }
            }
            if (value != string.Empty)
            {
                customer.CustomerID = Convert.ToUInt32(value);
                return Convert.ToUInt32(value);
            }
            else
            {
                return 0;
            }
        }

        public string GetCustomerName(uint custId)
        {
            SqlCommand sql = new SqlCommand(@"SELECT customer_name FROM customers_t WHERE customer_id = " + custId.ToString(), connection);
            string name = "";
            if (!ConnIsOpen())
            {
                connection.Open();
            }
            try
            {
                name = Convert.ToString(sql.ExecuteScalar());
            }
            catch (Exception ex)
            {
                StackTrace st = new StackTrace(new StackFrame(true));
                StackFrame sf = st.GetFrame(0);
                new ErrorThrower(sf, ex.Message);
            }
            finally
            {
                if (ConnIsOpen())
                {
                    connection.Close();
                }
            }
            customer.Name = name;
            return name;
        }

        public void PopulateTransactions()
        {
            customer.transactions.Clear();
            SqlCommand sql = new SqlCommand(@"SELECT * FROM transactions_t WHERE account_number = " + customer.AccountNumber, connection);
            if (!ConnIsOpen())
            {
                connection.Open();
            }
            try
            {
                SqlDataReader reader = sql.ExecuteReader();
                object[] values = new object[6];
                while (reader.Read())
                {
                    reader.GetValues(values);
                    customer.transactions.Add(new Transaction(values));
                }
            }
            catch (Exception ex)
            {
                StackTrace st = new StackTrace(new StackFrame(true));
                StackFrame sf = st.GetFrame(0);
                new ErrorThrower(sf, ex.Message);
            }
            finally
            {
                if (ConnIsOpen())
                {
                    connection.Close();
                }
            }
        }

        public void doStatement()
        {
            listBox1.Items.Clear();
            customer.balance = 0;
            int padding = 13;
            listBox1.Items.Add(string.Format("{0}|{1}|{2}|{3}|{4}","Date".PadRight(padding),"Transaction".PadRight(padding),"Withdrawal".PadRight(padding),"Deposit".PadRight(padding),"Balance".PadRight(padding)));
            listBox1.Items.Add("".PadLeft(padding * 5,'-'));

            ArrayList sout = new ArrayList();
            foreach (Transaction tran in customer.transactions)
            {
                if (tran.type == 'D')
                {
                    customer.balance += tran.amount;
                    sout.Add(string.Format("{0}|{1}|{2}|{3}|{4}", tran.date.ToShortDateString().PadRight(padding), (customer.CustomerID.ToString().PadLeft(4, '0') + "." + tran.id.ToString().PadLeft(4, '0')).PadRight(padding), "".PadRight(padding), tran.amount.ToString("C").PadRight(padding), customer.balance.ToString("C").PadRight(padding)));
                }
                else
                {
                    customer.balance -= tran.amount;
                    sout.Add(string.Format("{0}|{1}|{2}|{3}|{4}", tran.date.ToShortDateString().PadRight(padding), (customer.CustomerID.ToString().PadLeft(4, '0') + "." + tran.id.ToString().PadLeft(4, '0')).PadRight(padding), tran.amount.ToString("C").PadRight(padding), "".PadRight(padding), customer.balance.ToString("C").PadRight(padding)));
                }
            }
            sout.Reverse();
            foreach (String sthis in sout)
            {
                listBox1.Items.Add(sthis);
            }
        }

        public string GetAccountNumber(uint custId, string acctType)
        {
            string accountNumber = "";
            if (!ConnIsOpen())
            {
                connection.Open();
            }
            SqlCommand sql = new SqlCommand(@"SELECT account_number FROM accounts_t WHERE customer_id = " + custId.ToString() + " AND account_type = '" + acctType + "'", connection);
            try
            {
                accountNumber = sql.ExecuteScalar().ToString();
            }
            catch (Exception ex)
            {
                StackTrace st = new StackTrace(new StackFrame(true));
                StackFrame sf = st.GetFrame(0);
                new ErrorThrower(sf, ex.Message);
            }
            finally
            {
                if (ConnIsOpen())
                {
                    connection.Close();
                }
            }
            return accountNumber;
        }

        public bool InsertTransaction()
        {
            if (!ConnIsOpen())
            {
                connection.Open();
            }
            SqlCommand sql = new SqlCommand(@"INSERT INTO transactions_t (account_number,amount,transaction_type) " + 
                                            "VALUES ('" + this_transaction.account_number + "','" + this_transaction.amount + "','" + this_transaction.type + "')",
                                            connection);
            try
            {
                sql.ExecuteScalar();
            }
            catch (Exception ex)
            {
                StackTrace st = new StackTrace(new StackFrame(true));
                StackFrame sf = st.GetFrame(0);
                new ErrorThrower(sf, ex.Message);
                return false;
            }
            finally
            {
                if (ConnIsOpen())
                {
                    connection.Close();
                }
            }
            return true;
        }
    }

    class ErrorThrower
    {
        public ErrorThrower(StackFrame sf, string text)
        {
            MessageBox.Show(string.Format("Error: {0}\nLine:{1}\nFile:{2}", text, sf.GetFileLineNumber(), sf.GetFileName()), "Exception", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
        }
    }

    class SqlCredential
    {
        public string Server { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }
        public string Database { get; set; }

        public SqlCredential(string server, string username, string password, string database)
        {
            Server = server;
            Username = username;
            Password = password;
            Database = database;
        }

        public override string ToString()
        {
            return string.Format("Server={0};UID={1};PWD={2};Database={3}", Server, Username, Password, Database);
        }
    }
}
