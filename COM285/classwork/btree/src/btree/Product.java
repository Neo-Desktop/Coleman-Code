/******************************************************************************
 *     Project: btree                                                         *
 *  Class Name: Product                                                       *
 *      Author: Amrit Panesar <apanesar@coleman.edu>                          *
 *  Created On: Nov 7, 2012                                                   *
 *       Hours: X.XX Hours                                                    *
 *     Purpose: TODO: Write purpose here.                                     *
 ******************************************************************************/

package btree;

/**
 *
 * @author Amrit Panesar <apanesar@coleman.edu>
 */
public class Product {

    private int iProdNumb;
    private String sDescrpt;
    private double dPrice;
    private Product pGT = null;
    private Product pLT = null;

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

    public Product getpGT() {
        return pGT;
    }

    public void setpGT(Product pGT) {
        this.pGT = pGT;
    }

    public Product getpLT() {
        return pLT;
    }

    public void setpLT(Product pLT) {
        this.pLT = pLT;
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
    
    public boolean hasGT()
    {
        if(this.pGT != null) {
            return true;
        }
        else {
            return false;
        }
    }
    public boolean hasLT()
    {
        if(this.pLT != null) {
            return true;
        }
        else {
            return false;
        }
    }
    
    public boolean hasChild()
    {
        if(this.pGT != null || this.pLT != null)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
