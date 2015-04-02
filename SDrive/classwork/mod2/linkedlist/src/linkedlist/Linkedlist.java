/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlist;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Amrit Panesar <apanesar@coleman.edu>
 */
public class Linkedlist {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner inFile = null;
        try {
            inFile  = new Scanner(new FileReader("Product.csv"));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Linkedlist.class.getName()).log(Level.SEVERE, null, ex);
            System.out.print("File not found, please make product.csv");
            System.exit(0);
        }
        int count = -999;
        int arrfield = 0;
        while(inFile.hasNext())
        {
            String thisrowstring = inFile.nextLine();
            String[] thisrow = thisrowstring.split(",");
            arrfield = thisrow.length;
            if (count == -999) { count = 0; }
            count++;
        }
        inFile.close();
        try {
            inFile  = new Scanner(new FileReader("product.csv"));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Linkedlist.class.getName()).log(Level.SEVERE, null, ex);
            System.out.print("File not found, please make product.csv");
            System.exit(0);
        }
        String[][] csv = new String[count][arrfield];
        Product[] p = new Product[count];
        //System.out.println("count = "+count);
        //System.out.println("arrfield = "+arrfield);
        count = 0;
        while(inFile.hasNext())
        {
            String thisrowstring = inFile.nextLine();
            String[] thisrow = thisrowstring.split(",");
            int i = 0;
            for (String t:thisrow)
            {
                csv[count][i] = t;
                i++;
            }
            p[count] = new Product(csv[count]);
            //System.out.println(p[count].sDescrpt);
            if (count != 0) { p[count-1].next = p[count]; }
            //System.out.println(p[count].next);
            count++;
        }
        System.out.println("Item\tDescription\tPrice");
        Product q = p[0];
        while(q.hasNext())
        {
            System.out.println(q);
            q=q.next;
            if(q.hasNext() == false) {
                System.out.println(q);
            }
        }
    }
}
