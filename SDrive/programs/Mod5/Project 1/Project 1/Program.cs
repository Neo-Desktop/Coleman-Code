/******************************************************************************
 * Author: Amrit Panesar                                                      *
 * Project: 1                                                                 *
 * Date: 8/9/2013                                                             *
 * Due Date: Date Due: Monday Week 2 ( Midnight)                              *
 * Class: COM 271                                                             *
 * Teacher: S. Ganore                                                         *
 *                                                                            *
 * Filename: Program.cs                                                       *
 * File Description:                                                          *
 * Main driver for the project, instanciates employees and prints appropriate *
 * output.                                                                    *
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
    class Program
    {
        // the driver.
        static void Main(string[] args)
        {
            // make one employee for each type of employee
            Employee LazaroKeller = new Employee("Lazaro T. Keller", 0, DateTime.Parse("1/9/2013"));
            PartTimeEmployee JudithFranklin = new PartTimeEmployee("Judith J. Franklin", 1, DateTime.Parse("3/14/2013"), 15.50, 25);
            FullTimeEmployee SandraStockton = new FullTimeEmployee("Sandra E. Stockton", 2, DateTime.Parse("5/27/2013"), 68000);
            Consultant RichardRojas = new Consultant("Richard M. Rojas", 3, DateTime.Parse("8/28/2013"), 20, 40, 20.8, 500);

            // print them with their specific methods.
            Employee.Print(LazaroKeller);
            PartTimeEmployee.Print(JudithFranklin);
            FullTimeEmployee.Print(SandraStockton);
            Consultant.Print(RichardRojas);

            // finalize.
            Console.WriteLine("\n\nPress ENTER to continue...");
            Console.ReadLine();

        }
    }
}
