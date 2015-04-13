/******************************************************************************
 *     Project: Point 2                                                       *
 *  Class Name: point2                                                        *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/05/2012                                                    *
 *       Hours: 0.50 Hours                                                    *
 *     Purpose: Blah.                                                         *
 ******************************************************************************/
 
import javax.swing.*;

public class point2
{
    public static void main(String[] args) //main
    {
        String sMessage01 = "This application will accept the input of the "
                + "ammount of cookies the user has to organize into boxes and containers.\n"
                + "A box contains 24 cookies.\n"
                + "A container contains 75 boxes.";
        String sMessage02 = "This program will output the ammount of boxes, containers, and the underflow.";
        JOptionPane.showMessageDialog(null, sMessage01, "Welcome",
                                            JOptionPane.PLAIN_MESSAGE);
        JOptionPane.showMessageDialog(null, sMessage02, "Welcome",
                                            JOptionPane.PLAIN_MESSAGE);
        String input = JOptionPane.showInputDialog("Please enter the ammount of cookies.");
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
                    + "negative ammount of cookies.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
        
        String sOutMessage = "";
        Double dBoxes = dSide01 %24;
        Double dContainers = dBoxes %75;      
        
        int iContainers = (int) Math.floor(dContainers);
        if (dContainers > iContainers)
            iContainers++;
        
        int iBoxes = (int) Math.floor(dBoxes);
        if (dBoxes > iBoxes)
            iBoxes++;
        
        int iFullContainer = (int) Math.floor(dContainers);
        int iFullBoxes = iFullContainer * 75;
        int iLeftOverBoxes = iBoxes - iFullBoxes;
        int iLeftOverCookies = iLeftOverBoxes * 24;
        boolean bUnderFlow = false;
        
        sOutMessage += "You have a total of %d boxes with %d containers.\n";
        if (iContainers > dContainers)
        {
            sOutMessage += "The last container is not full.\n";
            bUnderFlow = true;
        }
        
        if(bUnderFlow)
        {
            sOutMessage += "You have %d boxes in the last container, with %d cookies.";
            System.out.format(sOutMessage, iBoxes, iContainers, iLeftOverBoxes, iLeftOverCookies);
        }
        else
        {
            System.out.format(sOutMessage, iBoxes, iContainers);
        }
        
    }
}