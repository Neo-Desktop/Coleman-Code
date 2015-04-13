/******************************************************************************
 *     Project: Project 1c                                                    *
 *  Class Name: Numbers                                                       *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/09/2012                                                    *
 *       Hours: 0.25 Hours                                                    *
 *     Purpose: To declare variables, constant variables, explore promotions  *
 *              explicit type casting, and display the results of these       *
 *              activities.                                                   *
 ******************************************************************************/
 
 public class Precedence // direction a
{
	public static void main(String[] args) // main
	{
		int iAmFour = 4, iAmTwo = 2, iAmSeven = 7, iAmFourteen = 14, iAmEightteen = 18, iAmFive = 5, iAmOne = 1, iAmTwentyEight = 28, iAmTwenty = 20, iAmThree = 3; // direction a
		double iAmPointTwo = 0.2; // direction a
		System.out.println( iAmFour + " + " + iAmSeven + " * " + iAmFour + " = " + (iAmFour+iAmSeven*iAmFour) ); // comp 1
		System.out.println( iAmFour + " / " + iAmTwo + " * " + iAmFourteen + " = " + (iAmFour/iAmTwo*iAmFourteen) ); // comp 2
		System.out.println( iAmEightteen + " / " + iAmTwo + " + " + iAmFourteen + " / " + iAmTwo + " = " + (iAmEightteen/iAmTwo+iAmFourteen/iAmTwo) ); // comp 3
		System.out.println( iAmFour + " + " + iAmTwo + " / " + iAmFour + " - " + iAmTwo + " = " + (iAmFour+iAmTwo/iAmFour-iAmTwo) ); // comp 4
		System.out.println( iAmFive + " % " + iAmTwo + " * " + iAmFour + " / " + iAmOne + " + " + iAmFive + " = " + (iAmFive%iAmTwo*iAmFour/iAmOne+iAmFive) ); // comp 5
		System.out.println( iAmTwentyEight + " / " + iAmFive + " = " + (iAmTwentyEight/iAmFive) ); // comp 6
		System.out.println( iAmTwentyEight + " % " + iAmFive + " = " + (iAmTwentyEight%iAmFive) ); // comp 7
		System.out.println( iAmTwenty + " / ( " + iAmFour + " + " + iAmOne + " ) = " + (iAmTwenty/(iAmFour+iAmOne)) ); // comp 8
		System.out.println( "( " + iAmTwo + " + " + iAmThree + " ) * " + iAmFour + " = " + ((iAmTwo+iAmThree)*iAmFour) ); // comp 9
		System.out.println( "24 / " + iAmPointTwo + " = " + (24/iAmPointTwo) ); // comp 10
		System.out.println( "----------------------------------------------------------------------------------------" );
		System.out.println( "Order of Precedence:" ); // direction c
		System.out.println( "1) Parentheses." ); // c
		System.out.println( "2) Multiplication, Division, Modulo - Left to Right." ); // c
		System.out.println( "3) Addition, Subtraction - Left to Right." ); // c
		System.out.println( "4) Assignment - Right to Left." ); // c
		System.out.println( "Multiplicative Operators are assosciated from Left to Right" ); // direction d
		System.out.println( "Addative Operators are assosciated from Left to Right" ); // d
		System.out.println( "Assignment Operators are assosciated from Right to Left" ); // d
	}
}

/* Output:

E:\programs\Mod1\Project1>java Precedence
4 + 7 * 4 = 32
4 / 2 * 14 = 28
18 / 2 + 14 / 2 = 16
4 + 2 / 4 - 2 = 2
5 % 2 * 4 / 1 + 5 = 9
28 / 5 = 5
28 % 5 = 3
20 / ( 4 + 1 ) = 4
( 2 + 3 ) * 4 = 20
24 / 0.2 = 120.0
----------------------------------------------------------------------------------------
Order of Precedence:
1) Parentheses.
2) Multiplication, Division, Modulo - Left to Right.
3) Addition, Subtraction - Left to Right.
4) Assignment - Right to Left.
Multiplicative Operators are assosciated from Left to Right
Addative Operators are assosciated from Left to Right
Assignment Operators are assosciated from Right to Left

*/