/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package project3;

/**
 *
 * @author 77260
 */
public class Inventory {
    public int iItemID;
    public String sItemName;
    public int iInStore;
    public double dManuPrice;
    public double dSellPrice;

    public Inventory() {
    }
    
    public Inventory(int iItemID, String sItemName, int iInStore, double dManuPrice, double dSellPrice) {
        this.iItemID = iItemID;
        this.sItemName = sItemName;
        this.iInStore = iInStore;
        this.dManuPrice = dManuPrice;
        this.dSellPrice = dSellPrice;
    }

    public double getdManuPrice() {
        return dManuPrice;
    }

    public void setdManuPrice(double dManuPrice) {
        this.dManuPrice = dManuPrice;
    }

    public double getdSellPrice() {
        return dSellPrice;
    }

    public void setdSellPrice(double dSellPrice) {
        this.dSellPrice = dSellPrice;
    }

    public int getiInStore() {
        return iInStore;
    }

    public void setiInStore(int iInStore) {
        this.iInStore = iInStore;
    }

    public int getiItemID() {
        return iItemID;
    }

    public void setiItemID(int iItemID) {
        this.iItemID = iItemID;
    }

    public String getsItemName() {
        return sItemName;
    }

    public void setsItemName(String sItemName) {
        this.sItemName = sItemName;
    }
    
    @Override
    public String toString()
    {
        return ""+this.getiInStore();
    }
}
