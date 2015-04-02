/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: CustomerHandler                                               *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 10/17/2012                                                    *
 *       Hours: 2.00 Hours                                                    *
 *     Purpose: To demonstrate the retention and knowledge of the previous    *
 *              mods concepts.                                                *
 *****************************************************************************/
package project2;

import java.util.Scanner;

/**
 *
 * @author 77260
 */
public class CustomerHandler {
    public static void invoke()
    {
        while(true)
        {
            int iSelect = menu();
            int iThing = doThing(iSelect);
            if (iThing == -999) {
                return;
            }
        }
    }
    public static int menu()
    {
        Scanner console = new Scanner(System.in);
        System.out.println(Project2.md.get(MenuHandler.CUSTOMER_MENU_ID));
        System.out.print(MenuHandler.PROMPT);
        String input = console.next();
        int iOut = 0;
        try
        {
            iOut = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            System.out.println("We're sorry. That was an invalid input, please try again.");
            iOut = menu();
        }
        if (iOut < 0 && iOut > 4)
        {
            System.out.println("We're sorry. That was an invalid input, please try again.");
            iOut = menu();
        }
        return iOut;
    }
    private static int doThing(int iSel) {
        switch (iSel)
        {
            case 1:
                AddCustomer();
                break;
            case 2:
                DeleteCustomer();
                break;
            case 3:
                ReportHandler.RunCustomerReport();
                break; 
            case 4:
                return -999;
        }
        return 0;
    }

    private static void AddCustomer() {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    private static void DeleteCustomer() {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    static Customer findCustomer() {
        String sPrompt = "Please enter either the ID or the name of the customer you wish to query.";
        Scanner console = new Scanner(System.in);
        System.out.println(sPrompt);
        System.out.print(MenuHandler.PROMPT);
        String input = console.next();
        boolean isID;
        try
        {
            Integer.parseInt(input);
            isID = true;
        }
        catch(Exception e)
        {
            isID = false;
        }
        if (isID)
        {
            for (int i=0;i<Project2.cu.size();i++)
            {
                Customer cust = Project2.cu.get(i);
                if (cust.getCustomerID() == Integer.parseInt(input))
                {
                    return cust;
                }
            }
            return null;
        }
        else
        {
            for (int i=0;i<Project2.cu.size();i++)
            {
                Customer cust = Project2.cu.get(i);
                if (cust.getCustomerName().equals(input))
                {
                    return cust;
                }
            }
            return null;
        }
    }
}
