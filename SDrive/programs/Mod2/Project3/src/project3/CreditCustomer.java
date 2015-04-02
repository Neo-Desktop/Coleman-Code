/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package project3;

/**
 *
 * @author 77260
 */
public class CreditCustomer extends Customer{
    private Customer customer;
    /**
     *Overrides Customer.java 's  Discount percent.
     */
    private double CustomerModifierPercent = +1.02;

    public CreditCustomer(Customer customer) {
        this.customer = customer;
        System.out.println("You are a credit customer, you are subject to a 2% markup");
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public double getCustomerModifierPercent() {
        return CustomerModifierPercent;
    }

    public void setCustomerModifierPercent(double CustomerModifierPercent) {
        this.CustomerModifierPercent = CustomerModifierPercent;
    }
    
    @Override
    public double doTotal(double dPrice)
    {
        return dPrice*(this.CustomerModifierPercent);
    }
    
}
