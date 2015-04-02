/*****************************************************************************
* Project: 2 - Payroll                                                       *
* Description: Implement a payroll system using abstract classes             *
* Author: Amrit Panesar - 77260                                              *
* License: Public Domain                                                     *
* File description: Houses the main driver for the program. Instantiates an  *
* array of 10 Employees that demonstrates polymorphic behavior               *
* For further description please see ARCHITECTURE.txt                        *
*****************************************************************************/

using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace Project2
{
    public partial class Program
    {
        static void Main(string[] args)
        {
            // Use an array list to house our employees.
            ArrayList empn = new ArrayList();

            // generate 5 to 30 random employees..
            int highOrder = RandNumber(5, 30);

            Console.WriteLine("Generating {0} Employees...", highOrder);

            // loop though the random number above
            for (int i = 0; i < highOrder; i++)
            {
                int thisN = RandNumber() % 5; // Generate a random number between 1 and the max integer size moded by 5 (to generate a number 1-4)
                switch (thisN)
                {
                    case 4: // BasePlus
                        empn.Add(new BasePlusCommissionEmployee(GenerateFirstName(), GenerateLastName(), GenerateSSN(), RandDouble(), (decimal)RandDouble(), (decimal)RandDouble()));
                        break;
                    case 3: // Commission
                        empn.Add(new CommissionEmployee(GenerateFirstName(), GenerateLastName(), GenerateSSN(), RandDouble(), (decimal)RandDouble()));
                        break;
                    case 2: // Salary
                        empn.Add(new SalariedEmployee(GenerateFirstName(), GenerateLastName(), GenerateSSN(), (decimal)RandDouble()));
                        break;
                    default: // Hourly
                        empn.Add(new HourlyEmployee(GenerateFirstName(), GenerateLastName(), GenerateSSN(), (decimal)RandDouble(), RandDouble()));
                        break;
                }
            }

            // Loop through the new array list.
            for (int i = 0; i < empn.Count; i++ )
            {
                Console.WriteLine("\n================Employee #: {0}================", (i + 1)); // spit out the squence number
                Console.WriteLine(empn[i]); // tostring method. so much easier.
                // remind me to always override the tostring() method.
            }

            // courtesy line and direction.
            Console.WriteLine("----------------------------------------\nPress ENTER to continue");
            // let's keep the console from closing.
            Console.ReadLine();
        }
    }
}
