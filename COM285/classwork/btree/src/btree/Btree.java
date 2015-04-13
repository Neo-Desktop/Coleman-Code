/******************************************************************************
 *     Project: btree                                                         *
 *  Class Name: Btree                                                         *
 *      Author: Amrit Panesar <apanesar@coleman.edu>                          *
 *  Created On: Nov 7, 2012                                                   *
 *       Hours: X.XX Hours                                                    *
 *     Purpose: TODO: Write purpose here.                                     *
 ******************************************************************************/

package btree;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Amrit Panesar <apanesar@coleman.edu>
 */
public class Btree {

    /**
     * @param argv the command line ARGument Vector
     */
    public static void main(String[] args) {
        int argc = args.length;
               Scanner inFile = null;
        try {
            inFile  = new Scanner(new FileReader("Product.csv"));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Btree.class.getName()).log(Level.SEVERE, null, ex);
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
            Logger.getLogger(Btree.class.getName()).log(Level.SEVERE, null, ex);
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
            if(count == 0) {
                count++;
                continue;
            }
            Product w = p[0];
            while(true)
            {
                if(w.getiProdNumb() <= p[count].getiProdNumb())
                {
                    if (w.hasLT())
                    {
                        w = w.getpLT();
                        continue;
                    }
                    else
                    {
                       w.setpLT(p[count]);
                       break;
                    }
                }
                else
                {
                    if (w.hasGT())
                    {
                        w = w.getpGT();
                        continue;
                    }
                    else
                    {
                       w.setpGT(p[count]);
                       break;
                    }
                }
            }
            count++;
        }
        System.out.println("Item\tDescription\tPrice");
        iot(p[0]);
    }
    public static void iot(Product theRootNode)
    {
       if (theRootNode != null) {
          iot(theRootNode.getpGT());
          System.out.println(theRootNode);
          //System.out.println("\t\\- R Sibling -> "+theRootNode.getpGT());
          //System.out.println("\t\\- L Sibling -> "+theRootNode.getpLT());
          iot(theRootNode.getpLT());
       }
    }
}
