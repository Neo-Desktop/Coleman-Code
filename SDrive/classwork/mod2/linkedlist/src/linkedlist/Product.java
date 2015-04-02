/******************************************************************************
 *     Project: linkedlist                                                    *
 *  Class Name: Product                                                       *
 *      Author: Amrit Panesar <apanesar@coleman.edu>                          *
 *  Created On: Nov 5, 2012                                                   *
 *       Hours: X.XX Hours                                                    *
 *     Purpose: TODO: Write purpose here.                                     *
 ******************************************************************************/

package linkedlist;

/**
 *
 * @author Amrit Panesar <apanesar@coleman.edu>
 */
public class Product {
    public int iProdNumb;
    public String sDescrpt;
    public double dPrice;
    public Product next = null;

    public Product(int iProdNumb, String sDescrpt, double dPrice) {
        this.iProdNumb = iProdNumb;
        this.sDescrpt = sDescrpt;
        this.dPrice = dPrice;
    }

    public Product(String[] arr) {
        if(arr.length == 3)
        {
            this.iProdNumb = Integer.parseInt(arr[0]);
            this.sDescrpt = arr[1];
            this.dPrice = Double.parseDouble(arr[2]);
        }
    }   

    public Product() {
    }

    public int getiProdNumb() {
        return iProdNumb;
    }

    public  void setiProdNumb(int iProdNumb) {
        this.iProdNumb = iProdNumb;
    }

    public  String getsDescrpt() {
        return sDescrpt;
    }

    public  void setsDescrpt(String sDescrpt) {
        this.sDescrpt = sDescrpt;
    }

    public  double getdPrice() {
         return dPrice;
    }

    public  void setdPrice(double dPrice) {
        this.dPrice = dPrice;
    }
    
    @Override
    public String toString()
    {
        return this.iProdNumb+"\t"+this.sDescrpt+"\t"+this.dPrice;
    }
    
    public boolean hasNext()
    {
        if (this.next != null) {
            return true;
        }
        else {
            return false;
        }
    }
}
