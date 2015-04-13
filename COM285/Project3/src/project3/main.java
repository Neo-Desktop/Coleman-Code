/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package project3;

import java.util.ArrayList;

/**
 *
 * @author 77260
 */
public class main {

    protected static ArrayList<Inventory>   al = inventory_init();
    protected static ArrayList<Customer>    cu = customer_init();
    protected static ArrayList<Order>       or = order_init();
    
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
    
    protected static String[] customer_get(char type) {
        String[] ret = new String[cu.size()];
        int count = 0;
        switch(type) {
            case 'a':
                for(Customer x:cu) {
                    ret[count] = ""+x.CustomerID;
                    count++;
                }
            break;
            case 'b':
                for(Customer x:cu){
                    ret[count] = ""+x.getCustomerName();
                    count++;
                }
            break;
        }
        return ret;
    }
    
    protected static String[] item_get(char type) {
        String[] ret = new String[al.size()];
        int count = 0;
        switch(type) {
            case 'a':
                for(Inventory x:al) {
                    ret[count] = ""+x.getiItemID();
                    count++;
                }
            break;
            case 'b':
                for(Inventory x:al){
                    ret[count] = ""+x.getsItemName();
                    count++;
                }
            break;
        }
        return ret;
    }
    
    protected static ArrayList<Order> order_init() {
        ArrayList<Order> or = new ArrayList<Order>(5);
        return or;
    }

}
