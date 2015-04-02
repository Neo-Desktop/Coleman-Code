/******************************************************************************
 * Author: Amrit Panesar                                                      *
 * Project: 1                                                                 *
 * Date: 8/9/2013                                                             *
 * Due Date: Date Due: Monday Week 2 ( Midnight)                              *
 * Class: COM 271                                                             *
 * Teacher: S. Ganore                                                         *
 *                                                                            *
 * Filename: FullTimeEmployee.cs                                              *
 * File Description:                                                          *
 * derived from employee. constructor requires same variables as employee.    *
 * full time employess are based on salarey and includes appropriate variables*
 * this class also includes a print function to assist in the display of data *
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
    class FullTimeEmployee : Employee
    {
        //FullTimeEmployee contains salary as the member variables.
        decimal salary;
        public decimal Salary { get { return salary; } set { salary = value; } }

        // constructor passes the values: name, id, and doh to the based constructor
        public FullTimeEmployee(string name, int id, DateTime doh, decimal salary)
            : base(name, id, doh)
        {
            this.Salary = salary;
        }

        // wage = salary.
        public decimal CalcWage()
        {
            return Salary;
        }

        // print full time information.
        public static void Print(FullTimeEmployee e)
        {
            Employee.Print(e);
            Console.Out.WriteLine("Type of Employee: Full time");
            Console.Out.WriteLine("Wage: {0}", e.CalcWage().ToString("C").PadLeft(9));
        }
    }
}
