/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: CreditCustomer                                                *
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
