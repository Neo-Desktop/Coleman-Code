/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: Project2                                                      *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 10/17/2012                                                    *
 *       Hours: 2.00 Hours                                                    *
 *     Purpose: To demonstrate the retention and knowledge of the previous    *
 *              mods concepts.                                                *
 *****************************************************************************/
package project2;
import java.util.*;

/**
 *
 * @author Amrit Panesar
 */
public class Project2 {

    /**
     * @param args the command line arguments
     */
    protected static ArrayList<MenuDialog>  md = MenuHandler.menu_dialog_init();
    
    protected static ArrayList<Inventory>   al = MenuHandler.inventory_init();
    protected static ArrayList<Customer>    cu = MenuHandler.customer_init();
    protected static ArrayList<Order>       or = MenuHandler.order_init();

    public static void main(String[] args) { // main()
        while(true)
        {
            int iSelect = menu();
            doThing(iSelect);
        }
    }

    public static int menu()
    {
        Scanner console = new Scanner(System.in);
        System.out.println(md.get(MenuHandler.MAIN_MENU_ID));
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
    
    private static void doThing(int iSel) {
        switch (iSel)
        {
            case 1:
                CustomerHandler.invoke();
                break;
            case 2:
                OrderHandler.invoke();
                break;
            case 3:
                InventoryHandler.invoke();
                break; 
            case 4:
                ReportHandler.invoke();
                break;
            case 5:
                exit();
                break;
        }
    }

    private static void exit() {
        System.exit(0);
    }
}
