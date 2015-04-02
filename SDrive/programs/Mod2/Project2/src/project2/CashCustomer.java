/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: CashCustomer                                                  *
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
