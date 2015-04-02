/*****************************************************************************
* Project: 2 - Payroll                                                       *
* Description: Implement a payroll system using abstract classes             *
* Author: Amrit Panesar - 77260                                              *
* License: Public Domain                                                     *
* File description: Contains the member variables and functions for hybrid   *
* commission/salary based employees.                                         *
* For further description please see ARCHITECTURE2.txt                       *
*****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project3
{
    public class BasePlusCommissionEmployee : CommissionEmployee
    {
        // overloaded constructor to call the Commission Employee's overloaded constructor
        public BasePlusCommissionEmployee(string FirstName, string LastName, string SSN, double ComissionRate, decimal GrossSales, decimal basesalary)
            : base(FirstName, LastName, SSN, ComissionRate, GrossSales)
        {
            BaseSalary = basesalary;
        }

        public decimal BaseSalary { get; set; }

        public override decimal Earnings()
        {
            // a salary/commission employee's wage is their salary + commission rate * gross sales 
            return (((decimal)ComissionRate * GrossSales) + BaseSalary);
        }

        // override the tostring method.
        public override string ToString()
        {
            // report employee tostring, gross sales, commission rate, and base salary
            return String.Format("base salaried commission employee: {0} {1}\nssn: {2}\ngross sales: {3}\ncommission rate: {4}\nbase salary: {5}\nearnings: {6}\n", FirstName, LastName, SocialSecuityNumber, GrossSales.ToString("C"), ComissionRate.ToString("F2"), BaseSalary.ToString("C"), Earnings().ToString("C"));
            // NOTE: we couldn't use the base.tostring method because it outputs commission employee strings.
        }
    }
}
