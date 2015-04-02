/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: MenuHandler                                                   *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 10/17/2012                                                    *
 *       Hours: 2.00 Hours                                                    *
 *     Purpose: To demonstrate the retention and knowledge of the previous    *
 *              mods concepts.                                                *
 *****************************************************************************/
package project2;

import java.util.ArrayList;

/**
 *
 * @author 77260
 */
public class MenuHandler {
    
protected static ArrayList<MenuDialog> menu_dialog_init() {
        ArrayList<MenuDialog> md = new ArrayList<MenuDialog>(1);
        md.add(0, new MenuDialog(0, "Main Menu",
"---------------------------------Main Menu----------------------------------\n"+
"1) Customer Actions                                                         \n"+
"2) Order Actions                                                            \n"+
"3) Inventory Actions                                                        \n"+
"4) Report Actions                                                           \n"+
"5) Exit                                                                     \n"+
"      Please enter your selection. Numbers 1-5 are accepted."));
        md.add(1, new MenuDialog(1, "Customer Manipulation Menu",
"-------------------------Customer Manipulation Menu-------------------------\n"+
"1) Add Customer                                                             \n"+
"2) Delete Customer                                                          \n"+
"3) Run Customer Report                                                      \n"+
"4) Back to Main Menu                                                        \n"+
"      Please enter your selection. Numbers 1-4 are accepted."));
        md.add(2, new MenuDialog(2, "Order Manipulation Menu",
"---------------------------Order Manipulation Menu--------------------------\n"+
"1) New Order                                                                \n"+
"2) Remove Order                                                             \n"+
"3) Run Order Report                                                         \n"+
"4) Back to Main Menu                                                        \n"+
"      Please enter your selection. Numbers 1-4 are accepted."));
        md.add(3, new MenuDialog(2, "Inventory Manipulation Menu",
"------------------------Inventory Manipulation Menu-------------------------\n"+
"1) Add Items to Inventory                                                   \n"+
"2) Delete Items From Inventory                                              \n"+
"3) Edit Inventory Quantities                                                \n"+
"4) Run Inventory Report                                                     \n"+
"5) Back to Main Menu                                                        \n"+
"      Please enter your selection. Numbers 1-5 are accepted."));
        md.add(4, new MenuDialog(2, "Report Display Menu",
"-----------------------------Report Display Menu----------------------------\n"+
"1) Run Customer Report                                                      \n"+
"2) Run Order Report                                                         \n"+
"3) Run Inventory Report                                                     \n"+
"4) Back to Main Menu                                                        \n"+
"      Please enter your selection. Numbers 1-4 are accepted."));
        return md;
    }
    /*  ItemID     itemName          pInStore  manufPrice   sellingPrice
     *   12   Circular saw              150    $   45.00    $  125.00
     *  235   Cooking range              50    $  450.00    $  850.00
     *  301   Table saw                 100    $  125.00    $  300.00
     *  302   Stapler                   300    $   18.00    $   49.00
     *  303   Lawn tractor                5    $  300.00    $  650.00
     */
protected static ArrayList<Inventory> inventory_init()
    {
        ArrayList<Inventory> al = new ArrayList<Inventory>(5);
        al.add(0, new Inventory(12,"Circular saw", 150, 45.00, 125.00));
        al.add(1, new Inventory(235,"Cooking range", 50, 450.00, 850.00));
        al.add(2, new Inventory(301,"Table saw", 100, 125.00, 300.00));
        al.add(3, new Inventory(302,"Stapler\t", 300, 18.00, 49.00));
        al.add(4, new Inventory(303,"Lawn tractor", 5, 300.00, 650.00));
        return al;
    }

protected static ArrayList<Customer> customer_init() {
        ArrayList<Customer> cu = new ArrayList<Customer>(5);
        cu.add(0,new Customer(0, "Kermit Thefrog", "8888 Balboa Avenue", "", "San Diego", "CA", "92123"));
        return cu;
    }
    static ArrayList<Order> order_init() {
        ArrayList<Order> or = new ArrayList<Order>(5);
        return or;
    }

    public final static int MAIN_MENU_ID = 0;
    public final static int CUSTOMER_MENU_ID = 1;
    public final static int ORDER_MENU_ID = 2;
    public final static int INVENTORY_MENU_ID = 3;
    public final static int REPORT_MENU_ID = 4;
    public final static String PROMPT = ":";
    
}
