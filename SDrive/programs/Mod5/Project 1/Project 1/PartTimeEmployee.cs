/******************************************************************************
 * Author: Amrit Panesar                                                      *
 * Project: 1                                                                 *
 * Date: 8/9/2013                                                             *
 * Due Date: Date Due: Monday Week 2 ( Midnight)                              *
 * Class: COM 271                                                             *
 * Teacher: S. Ganore                                                         *
 *                                                                            *
 * Filename: PartTimeEmployee.cs                                              *
 * File Description:                                                          *
 * base class for consultant. derived from employee. requires same variables  *
 * as employee but also includes hourlyrate and hours worked. this also       *
 * includes a print function to assist in the displaying of data.             *
 *                                                                            *
 * Description:                                                               *
 * Finish the inheritance chain with a class, which contains the Main method. *
 * The students must script all the corresponding source code and produce a   *
 * clean compile of each step along the way towards the class with the Main   *
 * method.                                                                    *
 * The final step is the execution of the .exe file, which assigns values     *
 * through the public interface of the object and then displays the correct   *
 * values. This lab is to be coded individually and shown to the instructor.  *
 *                                                                            *
 * Project Specification:                                                     *
 * We have Employee, PartTimeEmployee, FullTimeEmployee and Consultant        *
 * classes. Employee is the base class, PartTimeEmployee and FullTimeEmployee *
 * are derived from it. Consultant is the derived class of PartTimeEmployee   *
 * (so Constultant is indirect derived class of Employee) and therefore we    *
 * have 3 level inheritance. Employee class contains name, id and             *
 * dateOfHire as the member variables. PartTimeEmployee contains hourlyRate   *
 * and hoursWorked as member variables. FullTimeEmployee contains salary as   *
 * the member variables. Consultant contains extraHours and consultantFee as  *
 * the member variables. Hours over 40 are considered as extra hours and is   *
 * applicable only to the consultant, more over the consultant will get paid  *
 * an additional 50% for the extra hours.                                     *
 ******************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project_1
{
    class PartTimeEmployee : Employee
    {
        //hourlyRate and hoursWorked as the member variables.
        double hourlyRate, hoursWorked;
        public double HourlyRate { get { return this.hourlyRate; } set { this.hourlyRate = value; } }

        // data validation: part time employees can only work 40 hours.
        public double HoursWorked {
            get {
                if (this.hoursWorked > 40)
                {
                    this.hoursWorked = 40;
                }
                return this.hoursWorked;
            }
            set {
                if (this.hoursWorked > 40)
                {
                    this.hoursWorked = 40;
                }
                else
                {
                    this.hoursWorked = value;
                }
            }
        }

        // the constructor passes name, id, and dateofhire to the base class.
        public PartTimeEmployee(string name, int id, DateTime doh, double hourlyRate, double hoursWorked)
            : base(name, id, doh)
        {
            this.HourlyRate = hourlyRate;
            this.HoursWorked = hoursWorked;
        }

        // hourly rate * hours worked = wage
        public decimal CalcWage()
        {
            return (decimal)(this.HourlyRate * this.hoursWorked);
        }

        // print what is necessary.
        public void Print()
        {
            Console.Out.WriteLine("Hours worked: {0}", this.HoursWorked);
            Console.Out.WriteLine("Hourly rate: {0}", this.HourlyRate);
        }

        // stub for printing as a part time employee.
        public static void Print(PartTimeEmployee e)
        {
            Print(e, true);
        }

        // print the detailed information
        public static void Print(PartTimeEmployee e, bool choice)
        {
            Employee.Print(e);
            if (choice)
            {
                Console.Out.WriteLine("Type of Employee: Part time");
                Console.Out.WriteLine("Wage: {0}", e.CalcWage().ToString("C").PadLeft(9));
            }
            e.Print();
        }
    }
}
