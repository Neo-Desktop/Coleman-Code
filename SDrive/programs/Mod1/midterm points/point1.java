/******************************************************************************
 *     Project: Point 1                                                       *
 *  Class Name: point1                                                        *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/05/2012                                                    *
 *       Hours: 0.50 Hours                                                    *
 *     Purpose: Blah.                                                         *
 ******************************************************************************/
 
import javax.swing.*;

public class point1
{
    public static void main(String[] args) //main
    {
        String sMessage01 = "This application will accept the input of the "
                + "lengths of the sides of a triangle and determine if it is a right triangle.\n"
                + "A triangle is a polygon with 3 sides and three angles.\n"
                + "A triangle is considered right if one of the angles is 90 degrees.";
        String sMessage02 = "This program will determine weather or not a triangle is right.";
        
        JOptionPane.showMessageDialog(null, sMessage01, "Welcome",
                                            JOptionPane.PLAIN_MESSAGE);
        JOptionPane.showMessageDialog(null, sMessage02, "Welcome",
                                            JOptionPane.PLAIN_MESSAGE);
        String input = JOptionPane.showInputDialog("Please enter a side length.");
        double dSide01 = 0;
        try
        {
            dSide01 = Double.parseDouble(input);
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        if (dSide01 < 0)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, you cannot have a "
                    + "negative side length.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        input = JOptionPane.showInputDialog("Please enter a side length.");
        double dSide02 = 0;
        try
        {
            dSide02 = Double.parseDouble(input);
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        if (dSide02 < 0)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, you cannot have a "
                    + "negative side length.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        input = JOptionPane.showInputDialog("Please enter a side length.");
        double dSide03 = 0;
        try
        {
            dSide03 = Double.parseDouble(input);
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        if (dSide03 < 0)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, you cannot have a "
                    + "negative side length.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        // big ugly boolean.
        // 	IF (intFirstSide * intFirstSide == intSecondSide * intSecondSide + intThirdSide * intThirdSide) ||
	//	(intSecondSide * intSecondSide == intFirstSide * intFirstSide + intThirdSide * intThirdSide)||
        //      (intThirdSide * intThirdSide == intFirstSide * intFirstSide + intSecondSide * intSecondSide)

        dSide01 = Math.pow(dSide01, 2);
        dSide02 = Math.pow(dSide02, 2);
        dSide03 = Math.pow(dSide03, 2);
        if  ((dSide01 == (dSide02 + dSide03)) ||
             (dSide02 == (dSide01 + dSide03)) ||
             (dSide03 == (dSide01 + dSide02)))
        {
            JOptionPane.showMessageDialog(null, "This is a right triangle.",
                "Thank You", JOptionPane.INFORMATION_MESSAGE);
        }
        else
        {
            JOptionPane.showMessageDialog(null, "This is NOT a right triangle.",
                "Thank You", JOptionPane.INFORMATION_MESSAGE);
        }
        System.exit(0);
    }
}