/******************************************************************************
 *     Project: Project 3d                                                    *
 *  Class Name: TempCon                                                       *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/23/2012                                                    *
 *       Hours: 1.50 Hours                                                    *
 *     Purpose: To demonstrate the ability to create a conventionally named   *
 *              java application, the parsing of numeric strings with         *
 *              exception handling, format numeric output using Decimal       *
 *              Format, write to and read from a simple text file, use Decimal*
 *              Format to format output                                       *
 *                                                                            *
 ******************************************************************************/
 
import javax.swing.*;
import java.io.*;
import java.util.*;

public class TempCon
{
	public static void main(String[] args) // main
	{
		String sCity = JOptionPane.showInputDialog("Please enter a city."); //4a
                sCity = sCity.toUpperCase();//4b
                
                String sDate = JOptionPane.showInputDialog("Please enter a date, mm/dd/yyyy."); //4c
                
                String sTemp = JOptionPane.showInputDialog("Please enter a temperature in Fahrenheit."); //4d
                double dTemp = 0;
                try
                {
                    dTemp = Double.parseDouble(sTemp); 
                }
                catch (NumberFormatException ex)
                {
                    JOptionPane.showMessageDialog(null, "We're sorry, \""+dTemp+"\" was an invalid input"
                            +"Please re-run the application.", "Fatal Error", JOptionPane.ERROR_MESSAGE);
                    System.exit(0);
                }
                double dTempc = (dTemp - 32) * (5.0/9.0);
                String sTempc = String.format("%.2f", dTempc);

                PrintWriter outFile = null;
                Scanner inFile = null;
                try
                {
                    outFile = new PrintWriter("tempfile.dat");
                    inFile  = new Scanner(new FileReader("tempfile.dat"));
                    String sOut = "Temperature for: "+sCity+"\non: "+sDate+"\n"
                        +dTemp+"\u00B0 Fahrenheit\n"+sTempc+"\u00B0 Celsius.";
                    String sIn = "";
                    
                    outFile.append(sOut);
                    outFile.flush();
                    sIn = inFile.nextLine() + "\n" + inFile.nextLine() + "\n" +
                          inFile.nextLine() + "\n" + inFile.nextLine();
                    
                    JOptionPane.showMessageDialog(null,sIn, "Temperature for: "+sCity,
                        JOptionPane.INFORMATION_MESSAGE);
                }
                catch (FileNotFoundException ex)
                {
                    JOptionPane.showMessageDialog(null, "We're sorry, please make a file named "
                    +"Tempfile.dat", "Fatal Error", JOptionPane.ERROR_MESSAGE);
                    System.exit(0);
                }
                catch (IOException ex)
                {
                    JOptionPane.showMessageDialog(null, "We're sorry, caught an I/o exception "
                    ,"Fatal Error", JOptionPane.ERROR_MESSAGE);
                    System.exit(0);
                }
                finally
                {
                    outFile.close();
                    inFile.close();
                }
                System.exit(0);
	}
}