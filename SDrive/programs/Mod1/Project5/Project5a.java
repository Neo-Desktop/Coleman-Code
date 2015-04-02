/******************************************************************************
 *     Project: Project 5a                                                    *
 *  Class Name: Project5a                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 10/04/2012                                                    *
 *       Hours: 0.20 Hours                                                    *
 *     Purpose: demonstrate proficiency in using Counted loops, proficiency in*
 *              using Sentinel controlled loops, proficiency in using Flag    *
 *              controlled loops, proficiency in using EOF controlled loops,  *
 *              proficiency in using Forever loops, providing appropriate     *
 *              documentation for programs, the use of conventional           *
 *              identifiers for classes and variables, the ability to use     *
 *              simple program testing techniques to ensure the quality of    *
 *              their work product, the use of white space for ensuring       *
 *              readability of program code, correct formulation of boolean   *
 *              expressions to be used in the control of iterative structures *
 ******************************************************************************/
import java.util.*;
import java.io.*;

public class Project5a
{
	public static void main(String[] args) // main
	{
		String sSent = "";
		Scanner inFile = null;
		Scanner console = new Scanner (System.in); //console
		String temp = "";
		while (!sSent.equals("!q"))
		{
                    System.out.println("Enter a name, type !q to quit");
                    temp = console.nextLine();
                    sSent = temp;
                    System.out.println(temp);
		}
	}
}

/* output:

E:\programs\Mod1\Project5>java Project5a
Enter a name, type !q to quit
Blah
Blah
Enter a name, type !q to quit
hjsdalkf
hjsdalkf
Enter a name, type !q to quit
Neo Anderson
Neo Anderson
Enter a name, type !q to quit
!q
!q

*/