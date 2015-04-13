/******************************************************************************
 *     Project: Project 1d                                                    *
 *  Class Name: Strings                                                       *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/13/2012                                                    *
 *       Hours: 0.16 Hours                                                    *
 *     Purpose: To declare variables, initalize, and display two strings      *
 *              Concarenate and display results                               *
  ******************************************************************************/
  
   public class Strings // direction 1
{
	public static void main(String[] args) // main
	{
		String sStr1 = "String1", sStr2 = "String2", sStr3 = ""; // direction 2
		System.out.println(sStr1 + "\n" + sStr2);
		char cH0 = 'H', cE0 = 'E', cL0 = 'L', cL1 = 'L', cO0 = 'O', cSpc = ' ', cW0 = 'W', cO2 = 'O', cR0  ='R', cL3 = 'L', cD0 = 'D', cExlm = '!'; // direction 3
		sStr3 = "" + cH0 + cE0 + cL0 + cL1 + cO0 + cSpc + cW0 + cO2 + cR0 + cL3 + cD0 + cExlm + "";
		System.out.println(sStr3); // direction 3
	}
}

/* Output:

E:\programs\Mod1\Project1>java Strings
String1
String2
HELLO WORLD!

*/