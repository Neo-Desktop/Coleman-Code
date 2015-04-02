/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: ReportHandler                                                 *
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
public class ReportHandler {
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
        System.out.println(Project2.md.get(MenuHandler.REPORT_MENU_ID));
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
                RunCustomerReport();
                break;
            case 2:
                RunOrderReport();
                break;
            case 3:
                RunInventoryReport();
                break; 
            case 4:
                return -999;
        }
        return 0;
    }

    protected static void RunInventoryReport() {
        int iItemCount = 0;
        double dWorth = 0.00;
        System.out.println("Item ID\tItem Name\tStock\tMFG Price\tSale Price");
        for (int i=0;i<Project2.al.size();i++)
        {
            Inventory item = Project2.al.get(i);
            System.out.println(item.getiItemID()+"\t"+item.getsItemName()+"\t"+
                    item.getiInStore()+"\t$"+item.getdManuPrice()+"\t\t$"+item.getdSellPrice());
            iItemCount += item.getiInStore();
            dWorth += (item.getiInStore()*item.getdManuPrice());
        }
        System.out.println("There are currently "+iItemCount+" items in store.");
        System.out.println("The total worh of the store is: $"+dWorth);
    }

    protected static void RunOrderReport() {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    protected static void RunCustomerReport() {
        System.out.println("ID\tName\t\tAddress1\tAddress2\tCity\tState\tZip");
        for (int i=0;i<Project2.cu.size();i++)
        {
            Customer cust = Project2.cu.get(i);
            System.out.printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                    cust.getCustomerID(), cust.getCustomerName(),
                    cust.getCustomerAddress1(), cust.getCustomerAddress2(),
                    cust.getCustomerCity(), cust.getCustomerState(),
                    cust.getCustomerZip());
        }
    }
}
