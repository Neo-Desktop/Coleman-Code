/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package project3;

/**
 *
 * @author 77260
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

    public Order(Customer customer, Inventory item, int quantity, double total)
        throws InsufcientQuantityException {
        this.customer = customer;
        this.item = item;
        if (item.getiInStore() > quantity)
        {
            throw new InsufcientQuantityException();
        }
        else {
            this.quantity = quantity;
        }
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

    private static class InsufcientQuantityException extends Exception {

        public InsufcientQuantityException() {
            
        }
    }
}
