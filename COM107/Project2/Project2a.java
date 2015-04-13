/******************************************************************************
 *     Project: Project 2a                                                    *
 *  Class Name: Project2a                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/15/2012                                                    *
 *       Hours: 0.25 Hours                                                    *
 *     Purpose: To demonstrate the ability to create a conventionally named   *
 *              java application, use comments to document the software,      *
 *              use imported software components, instantiante objects,       *
 *              use methods associated with objects of prebuilt classes,      *
 *              use of user friendly prompts, echos, and error messages,      *
 *              use try and catch to prevent hard software crashes.           *
 ******************************************************************************/
 
 import java.util.*;
 
 public class Project2a
{
	public static void main(String[] args) // main
	{
		Scanner console = new Scanner(System.in); // direction 1
		/* begin direction 2 */
		int iWholeNum01 = 0;
		try
			{
				System.out.print("Please input a whole number: "); // user friendly prompt
				iWholeNum01 = console.nextInt(); // grab user input
				System.out.println("Your number was: " + iWholeNum01 +"\n"); // user friendly echo
			}
		catch (Exception e)
			{
				System.out.println("\nWe're sorry, this was not a whole number.\n"+
					"Please re-run the program."); // (hopefully) user friendly error massage
				return; // end execution here. we want them to wisen up eh.
			}
			
		/* begin direction 3 */
		double dRealNum01 = 0.0;
		try
			{
				System.out.print("Please input a decimal number: "); // user friendly prompt
				dRealNum01 = console.nextDouble(); // grab user input
				System.out.println("Your number was: " + dRealNum01 +"\n"); // user friendly echo
			}
		catch (Exception e)
			{
				System.out.println("\nWe're sorry, this was not a real number.\n"+
					"Please re-run the program."); // (hopefully) user friendly error massage
				return; // end execution here. we want them to wisen up eh.
			}
			
		/* begin direction 4 */
		String sFirstName = "";
		System.out.print("Please enter your First name: ");  // user friendly prompt
		sFirstName = console.next(); // grab user input
		System.out.println("Your name is: " + sFirstName);  // user friendly echo
		
		// Done !
	}
}

/* Output:

E:\programs\Mod1\Project2>java Project2a
Please input a whole number: 50
Your number was: 50

Please input a decimal number: 25.0
Your number was: 25.0

Please enter your First name: Amrit Panesar
Your name is: Amrit

E:\programs\Mod1\Project2>java Project2a
Please input a whole number: error

We're sorry, this was not a whole number.
Please re-run the program.

*/