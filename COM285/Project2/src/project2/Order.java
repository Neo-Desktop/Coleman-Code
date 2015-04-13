/******************************************************************************
 *     Project: Project2                                                      *
 *  Class Name: Order                                                         *
 *      Author: Amrit Panesar <apanesar@coleman.edu>                          *
 *  Created On: Nov 21, 2012                                                  *
 *       Hours: X.XX Hours                                                    *
 *     Purpose: TODO: Write purpose here.                                     *
 ******************************************************************************/

package project2;

/**
 *
 * @author Amrit Panesar <apanesar@coleman.edu>
 */
public class Order {
    private Customer customer;
    private Inventory item;
    private int quantity;
    private double total;

    public Order() {
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    public Order(Customer customer, Inventory item, int quantity, double total) {
        this.customer = customer;
        this.item = item;
        this.quantity = quantity;
        this.total = total;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public Inventory getItem() {
        return item;
    }

    public void setItem(Inventory item) {
        this.item = item;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
    
    public double computePrice() {
        return (this.quantity * this.item.getdManuPrice());
    }
}
