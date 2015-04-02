/*****************************************************************************
* Project: 2 - Payroll                                                       *
* Description: Implement a payroll system using abstract classes             *
* Author: Amrit Panesar - 77260                                              *
* License: Public Domain                                                     *
* File description: Contains the member variables and functions for          *
* commission based employees.                                                *
* For further description please see ARCHITECTURE.txt                        *
*****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project2
{
    public class CommissionEmployee : Employee
    {
        // the main overloaded constructor, also call the base class Employee with it's overloaded constructor.
        public CommissionEmployee(string FirstName, string LastName, string SSN, double comissionrate, decimal grosssales ) : base( FirstName, LastName, SSN)
        {
            ComissionRate = comissionrate;
            GrossSales = grosssales;
        }

        // constructor to pass an employee and arguments, if necessary.
        public CommissionEmployee(Employee empn, double comissionrate, decimal grosssales) : base (empn)
        {
            ComissionRate = comissionrate;
            GrossSales = grosssales;
        }

        // constructor to pass an entire commission employee if necessary.
        public CommissionEmployee(CommissionEmployee empn) : base (empn)
        {
            ComissionRate = empn.ComissionRate;
            GrossSales = empn.GrossSales;
        }

        public double ComissionRate { get; set; }
        public decimal GrossSales { get; set; }

        public override decimal Earnings()
        {
            // a commission employee's earnings are the commission rate * gross sales
            return ((decimal)ComissionRate * GrossSales);
        }

        // override the tostring method
        public override string ToString()
        {
            // the base tostring, gross sales, commission rate, and earnings
            return String.Format("commission {0}\ngross sales: {1}\ncommission rate: {2}\nearnings: {3}\n", base.ToString(), GrossSales.ToString("C"), ComissionRate.ToString("F2"), Earnings().ToString("C"));
        }
    }
}
