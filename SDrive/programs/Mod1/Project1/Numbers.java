/******************************************************************************
 *     Project: Project 1b                                                    *
 *  Class Name: Numbers                                                       *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/08/2012                                                    *
 *       Hours: 0.25 Hours                                                    *
 *     Purpose: To declare variables, constant variables, explore promotions  *
 *              explicit type casting, and display the results of these       *
 *              activities.                                                   *
 ******************************************************************************/

public class Numbers // direction 1
{
	public static void main(String[] args) // main
	{
		int iNumberTwo = 765, iNumberThree = (int) 4.75, iNumberFour = 17, iNumberFive = -2; // direction a + b
		final int iNumberOne = 3; // as per directon a + c: iNumberOne must be constant
		double dRealOne = 54.3, dRealTwo = 85, dRealThree = 67.56, dRealFour = 2, dRealFive = 3.3; // direction d + e
		
		System.out.println("NumberOne stores " + iNumberOne); //direction f
		System.out.println("NumberTwo stores " + iNumberTwo); //f
		System.out.println("NumberThree stores " + iNumberThree); //f
		System.out.println("NumberFour stores " + iNumberFour); //f
		System.out.println("NumberFive stores " + iNumberFive); //f
		System.out.println("RealOne stores " + dRealOne); //f
		System.out.println("RealTwo stores " + dRealTwo); //f
		System.out.println("RealThree stores " + dRealThree); //f
		System.out.println("RealFour stores " + dRealFour); //f
		System.out.println("RealFive stores " + dRealFive); //f
		System.out.println("** Number Three is type casted as an integer"); // direction g
		System.out.println("** Real Two is implicitly promoted as a double"); // direction h
	}
}

/* Output:

E:\programs\Mod1\Project1>java Numbers
NumberOne stores 3
NumberTwo stores 765
NumberThree stores 4
NumberFour stores 17
NumberFive stores -2
RealOne stores 54.3
RealTwo stores 85.0
RealThree stores 67.56
RealFour stores 2.0
RealFive stores 3.3
** Number Three is type casted as an integer
** Real Two is implicitly promoted as a double

*/