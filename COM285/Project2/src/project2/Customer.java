/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: Customer                                                      *
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
public class Customer {
    protected int CustomerID;
    protected String CustomerName;
    protected String CustomerAddress1;
    protected String CustomerAddress2;
    protected String CustomerCity;
    protected String CustomerState;
    protected String CustomerZip;
    protected int CustomerPaymentType; // Customer.CASH, Customer.CREDIT
    
    public static final int CASH = 0;
    public static final int CREDIT = 1;
    
    /**
     * If extending this class, CustomerModifierPercent should be overridden.
     */
    protected double CustomerModifierPercent = 0;

    public Customer() {
    }

    public Customer(int CustomerID, String CustomerName, String CustomerAddress1, String CustomerAddress2, String CustomerCity, String CustomerState, String CustomerZip) {
        this.CustomerID = CustomerID;
        this.CustomerName = CustomerName;
        this.CustomerAddress1 = CustomerAddress1;
        this.CustomerAddress2 = CustomerAddress2;
        this.CustomerCity = CustomerCity;
        this.CustomerState = CustomerState;
        this.CustomerZip = CustomerZip;
    }

    public int getCustomerID() {
        return CustomerID;
    }

    public void setCustomerID(int CustomerID) {
        this.CustomerID = CustomerID;
    }

    public String getCustomerName() {
        return CustomerName;
    }

    public void setCustomerName(String CustomerName) {
        this.CustomerName = CustomerName;
    }

    public String getCustomerAddress1() {
        return CustomerAddress1;
    }

    public void setCustomerAddress1(String CustomerAddress1) {
        this.CustomerAddress1 = CustomerAddress1;
    }

    public String getCustomerAddress2() {
        return CustomerAddress2;
    }

    public void setCustomerAddress2(String CustomerAddress2) {
        this.CustomerAddress2 = CustomerAddress2;
    }

    public String getCustomerCity() {
        return CustomerCity;
    }

    public void setCustomerCity(String CustomerCity) {
        this.CustomerCity = CustomerCity;
    }

    public String getCustomerState() {
        return CustomerState;
    }

    public void setCustomerState(String CustomerState) {
        this.CustomerState = CustomerState;
    }

    public String getCustomerZip() {
        return CustomerZip;
    }

    public void setCustomerZip(String CustomerZip) {
        this.CustomerZip = CustomerZip;
    }

    public int getCustomerPaymentType() {
        return CustomerPaymentType;
    }

    public void setCustomerPaymentType(int CustomerPaymentType) {
        this.CustomerPaymentType = CustomerPaymentType;
    }
    
    public double doTotal(double dPrice)
    {
        return -9.99;
    }

}
