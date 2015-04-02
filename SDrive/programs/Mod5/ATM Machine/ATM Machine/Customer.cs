using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace ATM_Machine
{
    class Customer
    {
        public Customer()
        {
            transactions = new ArrayList();
        }
        public string Name { get; set; }
        public uint CustomerID { get; set; }
        public uint AccountNumber { get; set; }
        public uint ATMNumber { get; set; }
        public uint PIN { get; set; }
        public ArrayList transactions;
        public decimal balance { get; set; }
    }
    public class Transaction
    {
        public Transaction()
        {

        }
        public Transaction(uint id, uint account_number, decimal amount, char type, DateTime date)
        {
            this.id = id;
            this.account_number = account_number;
            this.amount = amount;
            this.type = type;
            this.date = date;
        }
        public Transaction(object[] values)
        {
            id = Convert.ToUInt32(values[0]);
            account_number = Convert.ToUInt32(values[1]);
            amount = Convert.ToDecimal(values[2]);
            type = Convert.ToChar(values[3]);
            date = (DateTime)values[4];
        }
        public uint id { get; set; }
        public uint account_number { get; set; }
        public decimal amount { get; set; }
        public char type { get; set; }
        public DateTime date { get; set; }
    }
}
