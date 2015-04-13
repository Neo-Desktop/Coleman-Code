/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: OrderHandler                                                  *
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
public class OrderHandler {
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
        System.out.println(Project2.md.get(MenuHandler.ORDER_MENU_ID));
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
                AddOrder();
                break;
            case 2:
                DeleteOrder();
                break;
            case 3:
                ReportHandler.RunOrderReport();
                break; 
            case 4:
                return -999;
        }
        return 0;
    }

    private static void AddOrder() {
        Order ord = new Order();
        Customer cust = CustomerHandler.findCustomer();
        if (cust == null)
        {
            Scanner console = new Scanner(System.in);
            String input;
            System.out.println("We're sorry. We were unable to find that customer, try again?");
            System.out.print("([Y]es/[N]o)"+MenuHandler.PROMPT);
            input = console.next();
            char cIn = input.toLowerCase().charAt(0);
            if (cIn == 'y') {
                AddOrder();
            }
            else
            {
                System.out.println("Your order has been canceled.");
                return;
            }
        }
        else
        {
            System.out.println("Welcome back "+ cust.getCustomerName()+"!");
        }
        int iArrayID = InventoryHandler.checkStock();
        if (iArrayID != -999) {
            doPurchase(iArrayID, cust, ord);
        }
    }

    private static void DeleteOrder() {
        throw new UnsupportedOperationException("Not yet implemented");
    }
  
    private static void doPurchase(int iArrayID, Customer cust, Order ord) {
        Inventory inv = Project2.al.get(iArrayID);
        int iStock = inv.getiInStore();
        String sDesc = inv.getsItemName();
        System.out.println("The selling price is currently: $"+inv.getdSellPrice()+"\n"+
                "How many would you like to purchase?");
        Scanner console = new Scanner(System.in);
        System.out.print(MenuHandler.PROMPT);
        String input = console.next();
        int iOut = -999;
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
                doPurchase(iArrayID, cust, ord);
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
            System.out.print("([Y]es/[N]o)"+MenuHandler.PROMPT);
            input = console.next();
            char cIn = input.toLowerCase().charAt(0);
            if (cIn == 'y') {
                doPurchase(iArrayID, cust, ord);
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
            System.out.print("([Y]es/[N]o)"+MenuHandler.PROMPT);
            input = console.next();
            char cIn = input.toLowerCase().charAt(0);
            if (cIn == 'y') {
                doPurchase(iArrayID, cust, ord);
            }
        } else {
            System.out.printf("Input accepted. Your order for "+
                    iOut+" "+sDesc+" will be placed. Your Subtotal today is: %.2f"
                    +"\nWill that be Cash or Credit?\n", (inv.getdSellPrice()*iOut));
            System.out.print("([C]ash/C[r]edit)"+MenuHandler.PROMPT);
            input = console.next();
            char cIn = input.toLowerCase().charAt(0);
            switch (cIn)
            {
                case 'c':
                    cust.setCustomerPaymentType(Customer.CASH);
                    break;
                case 'r':
                    cust.setCustomerPaymentType(Customer.CREDIT);
                    break;
            }
            Customer newcust = cashOrCredit(cust);
            System.out.printf("Input accepted. Your order for "+
                    iOut+" "+sDesc+" will be placed. Your GrandTotal today is: %.2f"
                    +"\nPlace order?\n", newcust.doTotal(inv.getdSellPrice()*iOut));
            System.out.print("([Y]es/[N]o)"+MenuHandler.PROMPT);
            input = console.next();
            cIn = input.toLowerCase().charAt(0);
            if (cIn == 'y') {
                System.out.printf("Thank you! Your order has been recieved.\n"
                        + "You will be billed $%.2f\n",newcust.doTotal(inv.getdSellPrice()*iOut));
                Project2.or.add(new Order(newcust,inv,iOut,newcust.doTotal(inv.getdSellPrice()*iOut)));
                InventoryHandler.removeStock(iArrayID,iOut);
                return;
            }
        }
        System.out.println("Your order has been canceled.");
    }

    private static Customer cashOrCredit(Customer cu) {
        switch(cu.getCustomerPaymentType())
        {
            case Customer.CASH:
                return new CashCustomer(cu);
            case Customer.CREDIT:
                return new CreditCustomer(cu);
            default:
                return null;
        }
    }
}
