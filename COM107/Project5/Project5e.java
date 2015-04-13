/******************************************************************************
 *     Project: Project 5e                                                    *
 *  Class Name: Project5e                                                     *
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

 public class Project5e
{
	public static void main(String[] args) // main
	{
		Scanner console = new Scanner (System.in); //console
		out:
		while (true)
		{
			System.out.println("Please enter either 'M', 'H', 'S', or 'E' "
					+ "to find out more about that filing type, or enter"
					+ " any other character to quit.");
			System.out.print(":");
			switch (console.next().toLowerCase().charAt(0))
			{
				case 'm':
					System.out.println("Married");
					break;
				case 'h':
					System.out.println("Head of Household");
					break;
				case 's':
					System.out.println("Single");
					break;
				case 'e':
					System.out.println("Exempt");
					break;
				default:
					break out;
			}
		}
	}
}

/*output:

E:\programs\Mod1\Project5>java Project5e
Please enter either 'M', 'H', 'S', or 'E' to find out more about that filing typ
e, or enter any other character to quit.
:m
Married
Please enter either 'M', 'H', 'S', or 'E' to find out more about that filing typ
e, or enter any other character to quit.
:h
Head of Household
Please enter either 'M', 'H', 'S', or 'E' to find out more about that filing typ
e, or enter any other character to quit.
:s
Single
Please enter either 'M', 'H', 'S', or 'E' to find out more about that filing typ
e, or enter any other character to quit.
:e
Exempt
Please enter either 'M', 'H', 'S', or 'E' to find out more about that filing typ
e, or enter any other character to quit.
:q

*/