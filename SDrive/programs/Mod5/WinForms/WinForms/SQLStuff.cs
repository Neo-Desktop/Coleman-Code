using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace WinForms
{
    public partial class Form1
    {
        public static SqlConnection connection;
        public bool SQLInit()
        {
            connection = new SqlConnection((string)(new SqlCredential("172.16.2.34", "db77260", "daeddb98", "db77260")).ToString());
            if (SQLReady())
            {
                connection.Open();
                SqlCommand sql = new SqlCommand(
                    @"
                    DECLARE @return_status int;
                    IF EXISTS
                    (
                        SELECT name
                        FROM sysobjects
                        WHERE name=N'transactions_t'
                        AND type='U'
                    )
                    BEGIN
                        SET @return_status = 0
                    END
                    ELSE
                       BEGIN
                           SET @return_status = 1
                       END
                    SELECT 'Return Status' = @return_status;
                    "
                    , connection);
                if ((int)sql.ExecuteScalar() == 1)
                {
                    MessageBox.Show("Creating transaction table","Notice",MessageBoxButtons.OK,MessageBoxIcon.Information);
                    sql = new SqlCommand(
                        @"CREATE TABLE transactions_t
                            (
                                transaction_number  INT NOT NULL IDENTITY(1,10),
                                account_number      NUMERIC(6),
                                amount              MONEY,
                                transaction_type    CHAR(1),
                                last_date_modified  DATETIME
                                                    DEFAULT GETDATE(),
                                CONSTRATINT         INT
                                PRIMARY KEY         CLUSTERED (transaction_number)                                
                            )"
                            , connection);
                    sql.ExecuteScalar();
                    sql = new SqlCommand(
                        @"DECLARE @return_status int;
                        IF EXISTS
                        (
                            SELECT name
                            FROM sysobjects
                            WHERE name=N'transactions_t'
                            AND type='U'
                        )
                        BEGIN
                            SET @return_status = 0
                        END
                        ELSE 
                            BEGIN
                                SET @return_status = 1
                            END
                        SELECT 'Return Status' = @return_status;"
                        , connection);
                    if ((int)sql.ExecuteScalar() == 1)
                    {
                        MessageBox.Show("Error: Table generation failed.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return false;
                    }
                    else
                    {
                        sql = new SqlCommand(
                              @"INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(2222, 1000, 'D');
                                INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(2222, 4000, 'D');
                                INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(2222, 3000, 'W');
                                INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(3333, 12000, 'D');
                                INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(3333, 7000, 'D');
                                INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(2222, 10000, 'D');
                                INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(3333, 4000, 'W');
                                INSERT INTO transactions_t (account_number, amount, transaction_type) VALUES(3333, 3000, 'D');
                             ",connection);
                        sql.ExecuteScalar();
                        MessageBox.Show("Sample data inserted correctly","Notice",MessageBoxButtons.OK,MessageBoxIcon.Information);
                    }
                }
                return true;
            }
            else
            {
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

        


        public string GetCustomerName(int custId)
        {
            SqlCommand sql = new SqlCommand(@"SELECT customer_name FROM customers_t WHERE customer_id = " + custId.ToString(), connection);
            string name = "";
            if (!ConnIsOpen())
            {
                connection.Open();
            }
            try
            {
                name = sql.ExecuteScalar().ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                if (ConnIsOpen())
                {
                    connection.Close();
                }
            }
            return name;
        }

        public string GetAccountNumber(int custId, string acctType)
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
                MessageBox.Show(ex.Message);
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

        public void PopulateListBox(string acct_num)
        {
            decimal totalDeposits = 0.00M;
            decimal totalWithdrawals = 0.00M;

            string strAmount = "";

            listBox1.BeginUpdate();
            listBox1.Items.Add("Deposits".PadLeft(19) + "Withdrawals".PadLeft(14));

            SqlDataAdapter da = null;
            DataSet ds = null;
            DataTable dt = null;

            string query = @"
                    SELECT transaction_type, amount
                    FROM transactions_t
                    WHERE account_number = " + acct_num;
            if (!ConnIsOpen())
            {
                connection.Open();
            }

            da = new SqlDataAdapter(query, connection);
            ds = new DataSet();
            da.Fill(ds, "transactions_t");
            dt = ds.Tables["transactions_t"];
            foreach (DataRow row in dt.Rows)
            {
                if (row["transaction_type"].Equals("D"))
                {
                    totalDeposits += Convert.ToDecimal(row["amount"]);
                    strAmount = String.Format("+{0:N}", row["amount"]);
                    listBox1.Items.Add(strAmount.PadLeft(19));
                }
                else
                {
                    totalWithdrawals += Convert.ToDecimal(row["amount"]);
                    strAmount = String.Format("-{0:N}", row["amount"]);
                    listBox1.Items.Add("".PadLeft(19) + strAmount.PadLeft(14));
                }
            }
            listBox1.Items.Add("Total:" + String.Format("{0:N}", totalDeposits).PadLeft(13) +
                String.Format("{0:N}", totalWithdrawals).PadLeft(14));
            listBox1.EndUpdate();
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
            return string.Format("Server={0};UID={1};PWD={2};Database={3}",Server,Username,Password,Database);
        }
    }

}
