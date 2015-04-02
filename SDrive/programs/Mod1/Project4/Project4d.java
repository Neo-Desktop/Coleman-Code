/******************************************************************************
 *     Project: Project 4d                                                    *
 *  Class Name: Project4d                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/10/2012                                                    *
 *       Hours: 0.20 Hours                                                    *
 *     Purpose: Evaluate the input of a char representing the taxpayer's      *
 *              filing status and reporting weather the taxpayer will be      *
 *              taxed as a single or married person.                          *
 *                                                                            *
 ******************************************************************************/

 import java.util.*;


public class Project4d
{
	public static void main(String[] args) // main
	{
            Scanner console = new Scanner (System.in);
            System.out.println("What is your gross pay?");
            double dGross = 0;
            String input = console.next();
            try
            {
                dGross = Double.parseDouble(input);k
            }
            catch (NumberFormatException nfe)
            {
                System.out.println("We're sorry, \""+input+"\" was an invalid "
                        + "input. Please re-run the program.");
                System.exit(0);
            }
            System.out.println("How many withholdings do you have?");
            int iWHold = 0;
            input = console.next();
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
            if (iWHold < 0)
            {
                System.out.println("We're sorry, \""+input+"\" was an invalid "
                        + "input. Please re-run the program.");
                System.exit(0);
            }
            System.out.println("Are you (M)arried (H)ead of Household or "
                    + "(S)ingle?");
            String sInput = console.next();
            char cStatus = sInput.toLowerCase().charAt(0);
            if (cStatus != 'm' && cStatus != 'h' && cStatus != 's')
            {
                System.out.println("We're sorry, \""+cStatus+"\", was an invalid"
                        + "input. Please re-run the program.");
                System.exit(0);
            }
            boolean bLowInc = false;
            if ((cStatus == 's' && dGross <= 522) ||
                (cStatus == 'm' && dGross <= 522 && iWHold <=1 ) ||
                (cStatus == 'm' && dGross <= 1044 && iWHold >=2 ) ||
                (cStatus == 'h' && dGross <= 1044))
            {
                bLowInc = true;
            }
            switch (cStatus)
            {
                case 's':
                    System.out.println("You are filing as single.");
                    break;
                case 'm':
                    System.out.println("You are filing as married.");
                    break;
                case 'h':
                    System.out.println("You are filing as head of household.");
                    break;
            }
            if (bLowInc)
                System.out.println("You ARE classified as low income");
            else
                System.out.println("You are NOT classified as low income");
        }
}
/* Output
F:\programs\Mod1\Project4>java Project4d
What is your gross pay?
1043
How many withholdings do you have?
1
Are you (M)arried (H)ead of Household or (S)ingle?
m
You are filing as married.
You are NOT classified as low income

F:\programs\Mod1\Project4>java Project4d
What is your gross pay?
1043
How many withholdings do you have?
1
Are you (M)arried (H)ead of Household or (S)ingle?
m
You are filing as married.
You are NOT classified as low income

F:\programs\Mod1\Project4>java Project4d
What is your gross pay?
1044
How many withholdings do you have?
2
Are you (M)arried (H)ead of Household or (S)ingle?
m
You are filing as married.
You ARE classified as low income

F:\programs\Mod1\Project4>java Project4d
What is your gross pay?
1045
How many withholdings do you have?
3
Are you (M)arried (H)ead of Household or (S)ingle?
m
You are filing as married.
You are NOT classified as low income
  */