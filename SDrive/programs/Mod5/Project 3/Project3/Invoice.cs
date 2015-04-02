/*****************************************************************************
 * Project: 3 - Payroll Interface                                            *
 * Description: Implement a payroll system using abstract classes and        *
 * interfaces                                                                *
 * Author: Amrit Panesar - 77260                                             *
 * License: Public Domain                                                    *
 * File description: Contains the member variables and functions for a       *
 * generic Invoice and accounts payable interface.                           *
 * For further description please see ARCHITECTURE3.txt                      *
 *****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project3
{
    class Invoice : IPayable
    {
        // default constructor
        public Invoice() { }

        // the main constructor, sets payment right away
        public Invoice(decimal payment)
        {
            PaymentAmount = payment;
        }

        // implement the IPayable interface
        public decimal PaymentAmount { get; set; }

        // return the payment amount variable for the interface
        public decimal GetPaymentAmount()
        {
            return PaymentAmount;
        }
    }
}
