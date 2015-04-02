/******************************************************************************
 *     Project: Project 1                                                     *
 *  Class Name: Project1                                                      *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 10/17/2012                                                    *
 *       Hours: 2.00 Hours                                                    *
 *     Purpose: To demonstrate the retention and knowledge of the previous    *
 *              mods concepts.                                                *
 *****************************************************************************/
package project1;
import java.util.*;

/**
 *
 * @author Amrit Panesar
 */
public class Project1 {

    /**
     * @param args the command line arguments
     */
    /*  ItemID     itemName          pInStore  manufPrice   sellingPrice
     *   12   Circular saw              150    $   45.00    $  125.00
     *  235   Cooking range              50    $  450.00    $  850.00
     *  301   Table saw                 100    $  125.00    $  300.00
     *  302   Stapler                   300    $   18.00    $   49.00
     *  303   Lawn tractor                5    $  300.00    $  650.00

     */
    public static ArrayList<Inventory> al = init();
    public static void main(String[] args) {
        // initalize - lets prime the pump.
        while(true)
        {
            int iSelect = menu();
            doThing(iSelect);
        }
    }
    public static ArrayList<Inventory> init()
    {
        ArrayList<Inventory> al = new ArrayList<Inventory>(5);
        al.add(0, new Inventory(12,"Circular saw", 150, 45.00, 125.00));
        al.add(1, new Inventory(235,"Cooking range", 50, 450.00, 850.00));
        al.add(2, new Inventory(301,"Table saw", 100, 125.00, 300.00));
        al.add(3, new Inventory(302,"Stapler\t", 300, 18.00, 49.00));
        al.add(4, new Inventory(303,"Lawn tractor", 5, 300.00, 650.00));
        return al;
    }
    public static int menu()
    {
        String menu =
"-------------------------------Inventory Menu-------------------------------\n"+
"1) Check Item Inventory                                                     \n"+
"2) Sell Item                                                                \n"+
"3) Item Stock Report                                                        \n"+
"4) Exit                                                                     \n"+
"      Please enter your selection. Numbers 1-4 are accepted.";
        Scanner console = new Scanner(System.in);
        System.out.println(menu);
        System.out.print(":");  
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
    public static void doThing(int iSel) {
        switch (iSel)
        {
            case 1:
                checkStock();
                break;
            case 2:
                sellItem();
                break;
            case 3:
                generateReport();
                break;  
            case 4:
                exit();
                break;
        }
    }
    public static int getItemID() {
        String sPrompt = "Please enter the ID of the item you wish to query.";
        Scanner console = new Scanner(System.in);
        System.out.println(sPrompt);
        System.out.print(":");
        String input = console.next();
        int iOut = 0;
        try
        {
            iOut = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            System.out.println("We're sorry. That was an invalid input, try again?");
            System.out.print("([Y]es/[N]o):");
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
    public static int getStock(int iID) {
        for (int i=0;i<al.size();i++)
        {
            Inventory item = al.get(i);
            if(item.getiItemID() == iID) {
                return i;
            }
        }
        return -999;
    }
    public static int checkStock(){
        int iID = getItemID();
        if (iID == -999) {
            return -999;
        }
        int iArrayID = getStock(iID);
        if(iArrayID == -999) {
            System.out.println("Item not found.");
        } else {
            Inventory inv = al.get(iArrayID);
            int iStock = inv.getiInStore();
            String sDesc = inv.getsItemName();
            System.out.println("Item ID - "+iID+" ("+sDesc+") Currently has "
                    +iStock+" items in stock.");
            return iArrayID;
        }
        return -999;
    }

    private static void sellItem() {
            int iArrayID = checkStock();
            if (iArrayID != -999) {
                doPurchase(iArrayID);
            }
    }

    private static void generateReport() {
        int iItemCount = 0;
        double dWorth = 0.00;
        System.out.println("Item ID\tItem Name\tStock\tMFG Price\tSale Price");
        for (int i=0;i<al.size();i++)
        {
            Inventory item = al.get(i);
            System.out.println(item.getiItemID()+"\t"+item.getsItemName()+"\t"+
                    item.getiInStore()+"\t$"+item.getdManuPrice()+"\t\t$"+item.getdSellPrice());
            iItemCount += item.getiInStore();
            dWorth += (item.getiInStore()*item.getdManuPrice());
        }
        System.out.println("There are currently "+iItemCount+" items in store.");
        System.out.println("The total worh of the store is: $"+dWorth);
    }

    private static void exit() {
        System.exit(0);
    }

    private static void doPurchase(int iArrayID) {
            Inventory inv = al.get(iArrayID);
            int iStock = inv.getiInStore();
            String sDesc = inv.getsItemName();
            System.out.println("The selling price is currently: $"+inv.getdSellPrice()+"\n"+
                    "How many would you like to purchase?");
            Scanner console = new Scanner(System.in);
            System.out.print(":");
            String input = console.next();
            int iOut = -999;
            try
            {
                iOut = Integer.parseInt(input);
            }
            catch (Exception e)
            {
                System.out.println("We're sorry. That was an invalid input, try again?");
                System.out.print("([Y]es/[N]o):");
                input = console.next();
                char cIn = input.toLowerCase().charAt(0);
                if (cIn == 'y') {
                    doPurchase(iArrayID);
                }
                else
                {
					System.out.println("Your order has been canceled.");
                    return;
                }
            }
            if (iOut <= 0)
            {
                System.out.println("We're sorry. That was an invalid ammount, try again?");
                System.out.print("([Y]es/[N]o):");
                input = console.next();
                char cIn = input.toLowerCase().charAt(0);
                if (cIn == 'y') {
                    doPurchase(iArrayID);
                }
                else
                {
					System.out.println("Your order has been canceled.");
                    return;
                }
            }
            if (iOut > inv.getiInStore())
            {
                System.out.println("We're sorry. We don't have that many in stock, try again?");
                System.out.print("([Y]es/[N]o):");
                input = console.next();
                char cIn = input.toLowerCase().charAt(0);
                if (cIn == 'y') {
                    doPurchase(iArrayID);
                }
            } else {
                System.out.println("Input accepted. Your order for "+
                        iOut+" "+sDesc+" will be placed. Confirm your order?");
                System.out.print("([Y]es/[N]o):");
                input = console.next();
                char cIn = input.toLowerCase().charAt(0);
                if (cIn == 'y') {
                    System.out.println("Thank you! Your order has been recieved.\n"
                            + "You will be billed $"+(inv.getdSellPrice()*iOut));
                    removeStock(iArrayID,iOut);
					return;
                }
            }
			System.out.println("Your order has been canceled.");
    }

    private static void removeStock(int iArrayID, int iOut) {
            Inventory inv = al.get(iArrayID);
            int iStock = inv.getiInStore();
            iStock -= iOut;
            inv.setiInStore(iStock);
            al.set(iArrayID, inv);
    }

}
