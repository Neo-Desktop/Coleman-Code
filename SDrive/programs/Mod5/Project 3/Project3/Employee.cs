/*****************************************************************************
* Project: 2 - Payroll                                                       *
* Description: Implement a payroll system using abstract classes             *
* Author: Amrit Panesar - 77260                                              *
* License: Public Domain                                                     *
* File description: Houses the main driver for the program. Instantiates an  *
* array of 10 Employees that demonstrates polymorphic behavior               *
* For further description please see ARCHITECTURE2.txt                       *
*****************************************************************************/

using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace Project3
{
    public abstract class Employee : IPayable
    {
        // empty constructor, don't do anything.
        public Employee() { }

        // main constructor, each value as a parameter.
        public Employee(string fname, string lname, string ssn)
        {
            FirstName = fname; LastName = lname; SocialSecuityNumber = ssn;
        }

        // we have the flexibility to pass in an entire new employee if necessary.
        public Employee(Employee empn)
        {
            FirstName = empn.FirstName; LastName = empn.LastName; SocialSecuityNumber = empn.SocialSecuityNumber;
        }

        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string SocialSecuityNumber { get; set; }

        // abstract. must be implemented by all other inherited classes.
        public abstract decimal Earnings();

        // implement the IPayable interface in the employee class
        // this was the easiest thing to do since Earnings() already exists.
        public decimal GetPaymentAmount() // this is a project 3 addition
        {
            return Earnings();
        }

        // override the tostring. this is the base tostring.
        public override string ToString()
        {
            // The standard employee: employee first name, last name, and social security number
            return String.Format("employee: {0} {1}\nssn: {2}", FirstName, LastName, SocialSecuityNumber);
        }
    }
}
