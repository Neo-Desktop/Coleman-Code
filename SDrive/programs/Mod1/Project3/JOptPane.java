/******************************************************************************
 *     Project: Project 3c                                                    *
 *  Class Name: JOptPane                                                      *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/20/2012                                                    *
 *       Hours: 0.25 Hours                                                    *
 *     Purpose: To demonstrate the ability to create a conventionally named   *
 *              java application, the parsing of numeric strings with         *
 *              exception handling, format numeric output using Decimal       *
 *              Format, write to and read from a simple text file, use Decimal*
 *              Format to format output                                       *
 *                                                                            *
 ******************************************************************************/

import javax.swing.*; //3

public class JOptPane //3
{
    public static void main(String[] args) //main
    {
        String input = JOptionPane.showInputDialog("Please enter a whole number."); //3a
        int iInt01;
        try
        {
            iInt01 = Integer.parseInt(input); //3b
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            //3c
            return;
        }
        JOptionPane.showMessageDialog(null, "Your number was: "+iInt01,
                "Success", JOptionPane.INFORMATION_MESSAGE);// 3d
            
        /*--double time--*/
        input = JOptionPane.showInputDialog("Please enter a decimal number."); //3e
        double dReal01;
        try
        {
            dReal01 = Double.parseDouble(input); //3f
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            //3g
            return;
        }
        JOptionPane.showMessageDialog(null, "Your number was: "+dReal01,
        "Success", JOptionPane.INFORMATION_MESSAGE);// 3d
    }
}