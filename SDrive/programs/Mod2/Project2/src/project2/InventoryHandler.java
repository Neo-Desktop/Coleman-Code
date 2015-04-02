/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: InventoryHandler                                              *
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
public class InventoryHandler {
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
        System.out.println(Project2.md.get(MenuHandler.INVENTORY_MENU_ID));
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
        if (iOut < 0 && iOut > 5)
        {
            System.out.println("We're sorry. That was an invalid input, please try again.");
            iOut = menu();
        }
        return iOut;
    }

    private static int doThing(int iSel)
    {
        switch (iSel)
        {
            case 1:
                AddInventory();
                break;
            case 2:
                DeleteInventory();
                break;
            case 3:
                EditInventory();
                break;
            case 4:
                ReportHandler.RunInventoryReport();
                break;
            case 5:
                return -999;
        }
        return 0;
    }

    private static void AddInventory() {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    private static void DeleteInventory() {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    private static void EditInventory() {
        throw new UnsupportedOperationException("Not yet implemented");
    }
    
    protected static int getItemID()
    {
        String sPrompt = "Please enter the ID of the item you wish to query.";
        Scanner console = new Scanner(System.in);
        System.out.println(sPrompt);
        System.out.print(MenuHandler.PROMPT);
        String input = console.next();
        int iOut = 0;
        try
        {
            iOut = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            System.out.println("We're sorry. That was an invalid input, try again?");
            System.out.print("([Y]es/[N]o)"+MenuHandler.PROMPT);
            input = console.next();
            char cIn = input.toLowerCase().charAt(0);
            if (cIn == 'y') {
                iOut = -999;
            }
            else {
                iOut = getItemID();
            }
        }
        return iOut;
    }

    protected static int getStock(int iID)
    {
        for (int i=0;i<Project2.al.size();i++)
        {
            Inventory item = Project2.al.get(i);
            if(item.getiItemID() == iID) {
                return i;
            }
        }
        return -999;
    }
    
    protected static int checkStock()
    {
        int iID = getItemID();
        if (iID == -999) {
            return -999;
        }
        int iArrayID = getStock(iID);
        if(iArrayID == -999) {
            System.out.println("Item not found.");
        } else {
            Inventory inv = Project2.al.get(iArrayID);
            int iStock = inv.getiInStore();
            String sDesc = inv.getsItemName();
            System.out.println("Item ID - "+iID+" ("+sDesc+") Currently has "
                    +iStock+" items in stock.");
            return iArrayID;
        }
        return -999;
    }

    protected static void removeStock(int iArrayID, int iOut)
    {
            Inventory inv = Project2.al.get(iArrayID);
            int iStock = inv.getiInStore();
            iStock -= iOut;
            inv.setiInStore(iStock);
            Project2.al.set(iArrayID, inv);
    }
}
