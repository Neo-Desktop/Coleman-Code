/******************************************************************************
 * Author: Amrit Panesar                                                      *
 * Project: 1                                                                 *
 * Date: 8/9/2013                                                             *
 * Due Date: Date Due: Monday Week 2 ( Midnight)                              *
 * Class: COM 271                                                             *
 * Teacher: S. Ganore                                                         *
 *                                                                            *
 * Filename: Employee.cs                                                      *
 * File Description:                                                          *
 * base class for the project. includes member variables for name, id and     *
 * date of hire. also includes a print function to ease displaying data.      *
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
    class Employee
    {
        //name, id and dateOfHire as the member variables.
        string name;
        int id;
        DateTime dateOfHire;

        public string Name { get { return this.name; } set { this.name = value; } }
        public int Id { get { return id; } set { this.id = value; } }
        public DateTime DateOfHire { get { return this.dateOfHire; } set { this.dateOfHire = value; } }

        // constructor to include name, id, and date of hire.
        public Employee(string name, int id, DateTime doh)
        {
            this.Name = name;
            this.Id = id;
            this.DateOfHire = doh;
        }

        // print employee specific information
        public static void Print(Employee e)
        {
            Console.Out.WriteLine("\n============Employee {0}============", e.Id);
            Console.Out.WriteLine("Name: {0}", e.Name);
            Console.Out.WriteLine("ID: {0}", e.Id);
            Console.Out.WriteLine("Date of Hire: {0}", e.DateOfHire.ToShortDateString());
        }
    }
}
