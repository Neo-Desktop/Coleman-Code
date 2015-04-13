/*********************************************
 *     Program: Project 1a                   *
 *      Author: Amrit Panesar -ASP ,o/       *
 * Last Edited: 08/07/2012                   *
 *       Hours: 0.20 Hours                   *
 * Purpose: create an application that       *
 * will display two of the folowing patterns *
 * ----------------------------------------- *
 * A) a 6 pointed star                       *
 * B) a pine tree shape composed of pound    *
 *     symbols                               *
 * C) your initals using each inital to      *
 *     create a large version of that letter *
 *********************************************/

public class Project1a // direction I
{
	public static void main(String[] args) // direction I
	{
		String star = "\t\t\t*\n\n\t\t      * * *\n\n\t\t   * * * * * *\n\n\t\t    * * * * * \n"+
					  "\n\t\t   * * * * * *\n\n\t\t      * * *\n\n\t\t\t*"; // direction A -> This is the star. It is centered.
					  
		String pine = "\t\t\t#\n\n\t\t       # #\n\n\t\t      # # #\n\n\t\t     # # # #\n\n\t\t\t#"; // direction B -> Pine tree like figure. Centered as well
		
		String init = "\t       AAA    SSSSS  PPPPPP  \n\t      AAAAA  SS      PP   PP \n\t     AA"+
					  "   AA  SSSSS  PPPPPP  \n\t     AAAAAAA      SS PP      \n\t     AA   AA  SSSSS  PP "; // direction c -> ASP. Centered.
					  
		String line = "\n\n--------------------------------------------------------------------------------\n\n"; // Flush.
		System.out.print(star); // Print the star
		System.out.print(line); // flush
		System.out.print(pine); // Print the pine
		System.out.print(line); // flush
		System.out.print(init); // initals
		System.out.print("\n\n"); // don't need another flush.
	}
}

/* Output:

E:\programs\Mod1\Project1>java Project1a
                        *

                      * * *

                   * * * * * *

                    * * * * *

                   * * * * * *

                      * * *

                        *

--------------------------------------------------------------------------------

                        #

                       # #

                      # # #

                     # # # #

                        #

--------------------------------------------------------------------------------

               AAA    SSSSS  PPPPPP
              AAAAA  SS      PP   PP
             AA   AA  SSSSS  PPPPPP
             AAAAAAA      SS PP
             AA   AA  SSSSS  PP

*/