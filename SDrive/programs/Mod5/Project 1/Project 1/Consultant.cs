/******************************************************************************
 * Author: Amrit Panesar                                                      *
 * Project: 1                                                                 *
 * Date: 8/9/2013                                                             *
 * Due Date: Date Due: Monday Week 2 ( Midnight)                              *
 * Class: COM 271                                                             *
 * Teacher: S. Ganore                                                         *
 *                                                                            *
 * Filename: Consultant.cs                                                    *
 * File Description:                                                          *
 * derived from parttimeemployee requires the same variables as parttimeemp.. *
 * Consultants may work more than 40 hours a week. they also have a consultant*
 * fee. this class's calculate wage function assists in the calculation of    *
 * the concultant's wage. the print function assists in the display of        *
 * consultant specific data.                                                  *
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
    class Consultant : PartTimeEmployee
    {
        //Consultant contains extraHours and consultantFee as the member variables.
        double extraHours;
        decimal consultantFee;

        public double ExtraHours { get { return extraHours; } set { extraHours = value; } }
        public decimal ConsultantFee { get { return consultantFee; } set { consultantFee = value; } }

        // call the base class with name, id, doh, hourly rate, and hours worked
        public Consultant(string name, int id, DateTime doh, double hourlyRate, double hoursWorked, double extraHours, decimal consultantFee)
            : base(name, id, doh, hourlyRate, hoursWorked)
        {

            this.ExtraHours = extraHours;
            this.ConsultantFee = consultantFee;
        }

        // ( ( hours worked * hourly rate ) + ( extra hours * ( hourly rate * 1.5 ) ) + consultant fee ) = wage
        new public decimal CalcWage()
        {
            return (decimal)((this.HoursWorked * this.HourlyRate) + (this.ExtraHours * (this.HourlyRate * 1.5))) + ConsultantFee;
        }

        // print consultant specific information
        public static void Print(Consultant e)
        {
            PartTimeEmployee.Print(e, false);
            Console.Out.WriteLine("Type of Employee: Consultant");
            Console.Out.WriteLine("Wage: {0}", e.CalcWage().ToString("C").PadLeft(9));
            Console.Out.WriteLine("Extra Hours worked: {0}", e.ExtraHours);
            Console.Out.WriteLine("Extra Hours rate: {0}", (e.HourlyRate * 1.5));
            Console.Out.WriteLine("Consultant Fee: {0}", e.ConsultantFee.ToString("C").PadLeft(9));
        }
    }
}
