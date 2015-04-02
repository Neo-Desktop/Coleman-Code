/*****************************************************************************
* Project: 2 - Payroll                                                       *
* Description: Implement a payroll system using abstract classes             *
* Author: Amrit Panesar - 77260                                              *
* License: Public Domain                                                     *
* File description: Contains the member variables and functions for hourly   *
* employees.                                                                 *
* For further description please see ARCHITECTURE2.txt                       *
*****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project3
{
    public class HourlyEmployee : Employee
    {
        // main constructor. pass variables to the Employee constructor
        public HourlyEmployee(string FirstName, string LastName, string SSN, decimal wage, double hours) : base(FirstName, LastName, SSN)
        {
            Wage = wage;
            Hours = hours;
        }

        // We can pass in an employee object and extra variables, if necessary
        public HourlyEmployee(Employee empn, decimal wage, double hours) : base (empn)
        {
            Wage = wage;
            Hours = hours;
        }

        // Or we can pass in an entire Hourly Employee and work with that.
        public HourlyEmployee(HourlyEmployee empn) : base(empn)
        {
            Wage = empn.Wage;
            Hours = empn.Hours;
        }

        public decimal Wage { get; set; }
        public double Hours { get; set; }

        public override decimal Earnings()
        {
            if (Hours <= 40) // if the employee's hours are less than 40 inclusive
            {
                return (Wage * 40); // multiply the wage by 40 hours
            }
            else if (Hours > 40) // if the employee's hours are more than 40
            {
                return (decimal)(40 * (double)Wage + (Hours - 40) * (double)Wage * 1.5); // the standard wage + time and a half for all hours over 40
            }
            else // this should never happen.
            {
                return 0;
            }
        }

        // override the tostring
        public override string ToString()
        {
            //the standard employee tostring, hourly wage, hours worked, and earnings
            return String.Format("hourly {0}\nhourly wage: {1}\nhours worked: {2}\nearnings: {3}\n", base.ToString(), Wage.ToString("C"), Hours.ToString("F2"), Earnings().ToString("C"));
        }
    }
}
