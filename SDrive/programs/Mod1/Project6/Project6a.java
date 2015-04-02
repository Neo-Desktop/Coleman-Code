/******************************************************************************
 *     Project: Project 6a                                                    *
 *  Class Name: Project6a                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/17/2012                                                    *
 *       Hours: 1.00 Hours                                                    *
 *     Purpose: To do things because Charlie tells us to                  d   *
 ******************************************************************************/

import javax.swing.*;

public class Project6a
{
    public static void main(String[] args) //main
    {
		double dNum1, dNum2;
		try
		{
			   input = JOptionPane.showInputDialog("Please enter your first number.");
			   dNum1 = Double.parseDouble(input);
			   input = JOptionPane.showInputDialog("Please enter your second number.");
			   dNum2 = Double.parseDouble(input);
		}
		add(dNum1,dNum2);
		
    }
	public static void add(double n1, double n2)
	{
		double result = n1 + n2;
		JOptionPane.showMessageDialog(null,
			"Adding your two numbers together yields: "+result,
			"Results",
			JOptionPane.INFORMATION_MESSAGE);
		return;
	}
	
}