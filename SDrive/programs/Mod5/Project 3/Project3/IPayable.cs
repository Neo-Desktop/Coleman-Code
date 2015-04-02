/*****************************************************************************
 * Project: 3 - Payroll Interface                                            *
 * Description: Implement a payroll system using abstract classes and        *
 * interfaces                                                                *
 * Author: Amrit Panesar - 77260                                             *
 * License: Public Domain                                                    *
 * File description: Contains the required functions to be implemented in    *
 * classes that implement this interface                                     *
 * For further description please see ARCHITECTURE3.txt                      *
 *****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project3
{
    interface IPayable
    {
        // GetPaymentAmount() must be implemented by everyone who uses this interface
        decimal GetPaymentAmount();
    }
}
