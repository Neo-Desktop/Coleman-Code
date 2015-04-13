/******************************************************************************
 *     Project: Project 4a                                                    *
 *  Class Name: Project4a                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/10/2012                                                    *
 *       Hours: 0.20 Hours                                                    *
 *     Purpose: Evaluate the input of a char representing the taxpayer's      *
 *              filing status and reporting weather the taxpayer will be      *
 *              taxed as a single or married person.                          *
 *                                                                            *
 ******************************************************************************/
 
import java.util.*;


public class Project4a
{
	public static void main(String[] args) // main
	{
            System.out.println("Are you (M)arried (H)ead of Household or "
                    + "(S)ingle?");
            Scanner console = new Scanner(System.in);
            String sInput = console.next();
            char cStatus = sInput.toLowerCase().charAt(0);
            
            if (cStatus != 'm' && cStatus != 'h' && cStatus != 's')
            {
                System.out.println("Invalid input \""+cStatus+"\", please re-run the program");
                System.exit(0);
            }
            if (cStatus != 'm')
                System.out.println("You are filing as Single");
            else
                System.out.println("You are filing as Married");
        }
}

/* Output:

E:\programs\Mod1\Project 4>java Project4a
Are you (M)arried (H)ead of Household or (S)ingle?
m
You are filing as Married

E:\programs\Mod1\Project 4>java Project4a
Are you (M)arried (H)ead of Household or (S)ingle?
h
You are filing as Single

E:\programs\Mod1\Project 4>java Project4a
Are you (M)arried (H)ead of Household or (S)ingle?
s
You are filing as Single

E:\programs\Mod1\Project 4>java Project4a
Are you (M)arried (H)ead of Household or (S)ingle?
4
Invalid input "4", please re-run the program

*/