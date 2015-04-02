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
                Console.WriteLine("\n================Employee #: {0}================", (i + 1)); // spit out the sequence number
                Console.WriteLine(empn[i]); // tostring method. so much easier.
                Console.WriteLine("GetPaymentAmount(): {0}", ((Employee)empn[i]).GetPaymentAmount().ToString("C")); // project 3 change
                // remind me to always override the tostring() method.
            }

            /**************************begin project 3 changes****************/

            // make an array list to satisfy the project 3 requirements
            ArrayList invoices = new ArrayList();

            // generate a new highOrder for invoices. between 5 and 30 again
            highOrder = RandNumber(5, 30);

            // add a random amount of invoices with a random value to our array list
            for (int i = 0; i < highOrder; i++)
            {
                invoices.Add(new Invoice((decimal)RandDouble())); //instantiate a new Invoice with a new random value
            }

            // loop through our newly added invoices
            for (int i = 0; i < invoices.Count; i++)
            {
                Console.WriteLine("\n================Invoice #: {0}================", (i + 1)); // output sequence number
                Console.WriteLine("GetPaymentAmount: {0}", ((Invoice)invoices[i]).GetPaymentAmount().ToString("C")); // and information
            }

            // courtesy line and direction.
            Console.WriteLine("\n----------------------------------------\nPress ENTER to continue");
            // let's keep the console from closing.
            Console.ReadLine();
        }
    }
}
