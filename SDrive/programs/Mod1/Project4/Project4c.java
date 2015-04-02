/******************************************************************************
 *     Project: Project 4c                                                    *
 *  Class Name: Project4c                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/10/2012                                                    *
 *       Hours: 0.20 Hours                                                    *
 *     Purpose: Evaluate the input of a char representing the taxpayer's      *
 *              filing status and reporting weather the taxpayer will be      *
 *              taxed as a single or married person.                          *
 *                                                                            *
 ******************************************************************************/
 
import java.util.*;


public class Project4c
{
	public static void main(String[] args) // main
	{
            Scanner console = new Scanner (System.in);
            System.out.println("How many withholdings do you have?");
            int iWHold = 0;
            String input = console.next();
            try
            {
                iWHold = Integer.parseInt(input);
            }
            catch (NumberFormatException nfe)
            {
                System.out.println("We're sorry, \""+input+"\" was an invalid "
                        + "input. Please re-run the program.");
                System.exit(0);
            }
            
            //input has been sanitized.
            int iHVal = 0;
            switch (iWHold)
            {
                case 1:
                    iHVal = 42;
                    break;
                case 2:
                    iHVal = 83;
                    break;
                case 3:
                    iHVal = 125;
                    break;
                case 4:
                    iHVal = 167;
                    break;
                case 5:
                    iHVal = 208;
                    break;
                case 6:
                    iHVal = 250;
                    break;
                case 7:
                    iHVal = 292;
                    break;
                case 8:
                    iHVal = 333;
                    break;
                case 9:
                    iHVal = 375;
                    break;
                case 10:
                    iHVal = 417;
                    break;
                default:
                    iHVal = iWHold * 42;
                    break;    
            }
            System.out.println (iWHold + " withholding allowances provides an "
                    + "estimated deduction of: $" +iHVal);
                    
        }
}

/*output:

E:\programs\Mod1\Project4>java Project4c
How many withholdings do you have?
1
1 withholding allowances provides an estimated deduction of: $42

E:\programs\Mod1\Project4>java Project4c
How many withholdings do you have?
1024
1024 withholding allowances provides an estimated deduction of: $43008

E:\programs\Mod1\Project4>java Project4c
How many withholdings do you have?
5
5 withholding allowances provides an estimated deduction of: $208

 */