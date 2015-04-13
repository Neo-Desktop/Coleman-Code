/******************************************************************************
 *     Project: Project 4e                                                    *
 *  Class Name: Project4e                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/10/2012                                                    *
 *       Hours: 0.20 Hours                                                    *
 *     Purpose: Evaluate the input of a char representing the taxpayer's      *
 *              filing status and reporting weather the taxpayer will be      *
 *              taxed as a single or married person.                          *
 *                                                                            *
 ******************************************************************************/

 import java.util.*;


public class Project4e
{
	public static void main(String[] args) // main
	{
            Scanner console = new Scanner (System.in); //console
            System.out.println("What is your gross pay?");
            double dGross = 0;
            String input = console.next(); //grab a string
            try
            {
                dGross = Double.parseDouble(input); // parse it
            }
            catch (NumberFormatException nfe) // bomb if it doesn't validate
            {
                System.out.println("We're sorry, \""+input+"\" was an invalid "
                        + "input. Please re-run the program.");
                System.exit(0);
            }
            if (dGross < 0)
            {
                System.out.println("We're sorry, \""+input+"\" was an invalid "
                        + "input. Please re-run the program.");
                System.exit(0);                
            }
            System.out.println("Are you (M)arried (H)ead of Household or "
                    + "(S)ingle?");
            String sInput = console.next(); // grab a string
            char cStatus = sInput.toLowerCase().charAt(0); // make it lowercase, grab the first character
            if (cStatus != 'm' && cStatus != 'h' && cStatus != 's') //only need to handle these
            {
                System.out.println("We're sorry, \""+cStatus+"\", was an invalid"
                        + "input. Please re-run the program.");
                System.exit(0);
            }
            double dBase = 0, dExcess = 0, dPercent = 0;
            if (cStatus == 's' || cStatus == 'h' ) {
                if (dGross <= 90)
                {
                    dBase = 0.00;
                    dPercent = 0.00;
                    dExcess = 0.00;
                }
                else if (dGross > 90 && dGross <=452)
                {
                    dBase = 0.00;
                    dPercent = 0.10;
                    dExcess = 90.00;
                }
                else if (dGross > 452 && dGross <= 1563)
                {
                    dBase = 36.20;
                    dPercent = 0.15;
                    dExcess = 452.00;
                }
                else if (dGross > 1563 && dGross <= 3658)
                {
                    dBase = 202.85;
                    dPercent = 0.25;
                    dExcess = 1563.00;
                }
                else if (dGross > 3658 && dGross <= 7533)
                {
                    dBase = 276.60;
                    dPercent = 0.28;
                    dExcess = 3658.00;
                }
                else if  (dGross > 7533 && dGross <= 16271)
                {
                    dBase = 4695.14;
                    dPercent = 0.33;
                    dExcess = 7533.00;
                }
                else if  (dGross > 16271)
                {
                    dBase = 4695.14;
                    dPercent = 0.35;
                    dExcess = 16271.00;
                }
                else
                {
                    System.out.println("Illogical.");
                    System.exit(0);
                }

            }
            else if (cStatus == 'm')
            {
                if  (dGross <= 338)
                {
                    dBase = 0.00;
                    dPercent = 0.00;
                    dExcess = 0.00;
                }
                else if  (dGross > 338 && dGross <=1063 )
                {
                    dBase = 0.00;
                    dPercent = 0.10;
                    dExcess = 338.00;
                }
                else if  (dGross > 1063 && dGross <= 3283)
                {
                    dBase = 72.50;
                    dPercent = 0.15;
                    dExcess = 1063.00;
                }
                else if  (dGross > 3283 && dGross <= 6283)
                {
                    dBase = 405.50;
                    dPercent = 0.25;
                    dExcess = 3283.00;
                }
                else if  (dGross > 6283 && dGross <= 9398)
                {
                    dBase = 1155.50;
                    dPercent = 0.28;
                    dExcess = 6283.00;
                }
                else if  (dGross > 9398 && dGross <= 16519)
                {
                    dBase = 2027.70;
                    dPercent = 0.33;
                    dExcess = 9398.00;
                }
                else if  (dGross > 16519 )
                {
                    dBase = 4377.63;
                    dPercent = 0.35;
                    dExcess = 16519.00;
                }
                else
                {
                    System.out.println("Illogical.");
                    System.exit(0);
                }

            }
            else
            {
                System.out.println("Illogical.");
                System.exit(0);
            }
            
            double dFed = dBase + ((dGross - dExcess) * dPercent);
            
            switch (cStatus)
            {
                case 'm':
                    System.out.println("You are filing as: Married");
                    break;
                case 's':
                    System.out.println("You are filing as: Single");
                    break;
                case 'h':
                    System.out.println("You are filing as: Head of Household");
                    break;
            }
            System.out.printf("You gross income is: $%.2f\n", dGross);
            System.out.printf("Therefore, your base tax is: $%.2f\n", dBase);
            System.out.printf("Your tax surcharge percentage is: %%%.2f\n", (dPercent*100));
            // System.out.printf("%s + ((%s - %s) * (%s/100)\n", dBase, dGross, dExcess, (dPercent*100)); // debugging.
            System.out.printf("Your withholding tax is: $%.2f\n", dFed);

        }
}

/* output:
S:\programs\Mod1\Project4>java Project4e
What is your gross pay?
31415
Are you (M)arried (H)ead of Household or (S)ingle?
s
You are filing as: Single
You gross income is: $31415.00
Therefore, your base tax is: $4695.14
Your tax surcharge percentage is: %35.00
Your withholding tax is: $9995.54

S:\programs\Mod1\Project4>java Project4e
What is your gross pay?
1231
Are you (M)arried (H)ead of Household or (S)ingle?
s
You are filing as: Single
You gross income is: $1231.00
Therefore, your base tax is: $36.20
Your tax surcharge percentage is: %15.00
Your withholding tax is: $153.05

S:\programs\Mod1\Project4>java Project4e
What is your gross pay?
555555
Are you (M)arried (H)ead of Household or (S)ingle?
m
You are filing as: Married
You gross income is: $555555.00
Therefore, your base tax is: $4377.63
Your tax surcharge percentage is: %35.00
Your withholding tax is: $193040.23
  */