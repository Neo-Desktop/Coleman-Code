/*****************************************************************************
* Project: 2 - Payroll                                                       *
* Description: Implement a payroll system using abstract classes             *
* Author: Amrit Panesar - 77260                                              *
* License: Public Domain                                                     *
* File description: Contains the member variables and functions for salaried *
* employees.                                                                 *
* For further description please see ARCHITECTURE2.txt                       *
*****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project3
{
    public class SalariedEmployee : Employee
    {
        // main constructor for the salaried employee
        public SalariedEmployee(string FirstName, string LastName, string SSN, decimal weeklysal) : base(FirstName, LastName, SSN)
        {
            WeeklySalary = weeklysal;
        }
        public decimal WeeklySalary { get; set; }

        public override decimal Earnings()
        {
            // a salaried employee's earnings are his/her weekly salary.
            return WeeklySalary;
        }

        public override string ToString()
        {
            // the standard employee tostring, weekly salary, and earnings
            return String.Format("salaried {0}\nweekly salary: {1}\nearnings: {2}\n",base.ToString(),WeeklySalary.ToString("C"),Earnings().ToString("C"));
        }
    }
}
