/******************************************************************************
 *     Project: Project 4b                                                    *
 *  Class Name: Project4b                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/10/2012                                                    *
 *       Hours: 0.20 Hours                                                    *
 *     Purpose: Evaluate the input of a char representing the taxpayer's      *
 *              filing status and reporting weather the taxpayer will be      *
 *              taxed as a single or married person.                          *
 *                                                                            *
 ******************************************************************************/
 
import java.util.*;


public class Project4b
{
	public static void main(String[] args) // main
	{
            System.out.println("Are you (M)arried (H)ead of Household (E)xempt "
                    + "or (S)ingle?");
            Scanner console = new Scanner(System.in);
            String sInput = console.next();
            char cStatus = sInput.toLowerCase().charAt(0);
            
            if (cStatus != 'm' && cStatus != 'h' && cStatus != 's')
            {
                System.out.println("You have elected for exempt status");
                System.exit(0);
            }
            if (cStatus == 'm')
                System.out.println("You are filing as Married");
            else if (cStatus == 's')
                System.out.println("You are filing as Single");
            else if (cStatus == 'h')
                System.out.println("You are filing as Head of Household");
        }
        
}
/* output:
E:\programs\Mod1\Project4>java Project4b
Are you (M)arried (H)ead of Household (E)xempt or (S)ingle?
m
You are filing as Married

E:\programs\Mod1\Project4>java Project4b
Are you (M)arried (H)ead of Household (E)xempt or (S)ingle?
head of household
You are filing as Head of Household

E:\programs\Mod1\Project4>java Project4b
Are you (M)arried (H)ead of Household (E)xempt or (S)ingle?
s
You are filing as Single

E:\programs\Mod1\Project4>java Project4b
Are you (M)arried (H)ead of Household (E)xempt or (S)ingle?
4
You have elected for exempt status
*/