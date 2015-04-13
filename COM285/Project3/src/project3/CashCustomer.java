/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package project3;

/**
 *
 * @author 77260
 */
public class CashCustomer extends Customer {
    /**
     *Overrides Customer.java 's  Discount percent.
     */
    private double CustomerModifierPercent = 0.02;
    private Customer customer;

    public CashCustomer(Customer customer) {
        this.customer = customer;
        System.out.println("You are a cash customer, you get a 2% discount!");
    }

    public double getCustomerModifierPercent() {
        return CustomerModifierPercent;
    }

    public void setCustomerModifierPercent(double CustomerModifierPercent) {
        this.CustomerModifierPercent = CustomerModifierPercent;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }
    
    @Override
    public double doTotal(double dPrice)
    {
        return dPrice-(dPrice*(this.CustomerModifierPercent));
    }
    
}