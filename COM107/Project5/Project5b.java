/******************************************************************************
 *     Project: Project 5b                                                    *
 *  Class Name: Project5b                                                     *
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

public class Project5b
{
	public static void main(String[] args) // main
	{
		Scanner inFile = null;
		try
		{
		  inFile = new Scanner(new FileReader("payrollData.txt"));
		}
		catch (Exception e)
		{
			System.exit(0);
		}
		for (int i=0;i<5;i++)
		{
			int iEmployee = inFile.nextInt();
			char cFiling = inFile.next().charAt(0);
			int iWHold = inFile.nextInt();
			char cClass = inFile.next().charAt(0);
			double dHours = inFile.nextDouble();
			double dPayR = inFile.nextDouble();
			double dSal = inFile.nextDouble();
			double dYTD = inFile.nextDouble();
			String sFOut = "";
			String sCout = "";
			
			
			if (cFiling == 's')
			{
				sFOut = "Single";
			}
			else if (cFiling == 'h' )
			{
				sFOut = "Head of Household";
			}
			else if (cFiling == 'm')
			{
				sFOut = "Married";
			}
			else
			{
				sFOut = "Illogical.";
			}
			
			if (cClass == 'h')
			{
				sCout = "Hourly";
			}
			else if (cClass == 's')
			{
				sCout = "Salary";
			}
			else
			{
				sCout = "Illigocial.";
			}
			
			String out = "Employee Number: "+ iEmployee + "\t" +
						 "Filing as: "+ sFOut + "\t" +
						 "Number of Withholdings: "+iWHold+ "\t"+
						 "Pay Type: "+sCout + "\t";
			if (cClass == 'h')
			{
				out += "Hours Worked: "+ dHours +"\t"+
						"Pay Rate: " + dPayR + "\t";
				
			}
			else
			{
				out += "Salary: " + dSal + "\t";
			}
			out += "Year To Date: " + dYTD + "\t";
			System.out.println(out);
		}
	}
}

/* output:

E:\programs\Mod1\Project5>java Project5b
Employee Number: 1001   Filing as: Single       Number of Withholdings: 11
Pay Type: Hourly        Hours Worked: 40.0      Pay Rate: 15.35 Year To Date: 12
28.0
Employee Number: 1002   Filing as: Single       Number of Withholdings: 10
Pay Type: Hourly        Hours Worked: 38.0      Pay Rate: 15.0  Year To Date: 57
0.0
Employee Number: 1003   Filing as: Single       Number of Withholdings: 9
Pay Type: Hourly        Hours Worked: 26.45     Pay Rate: 20.0  Year To Date: 10
58.0
Employee Number: 1004   Filing as: Single       Number of Withholdings: 8
Pay Type: Hourly        Hours Worked: 20.0      Pay Rate: 39.15 Year To Date: 23
49.0
Employee Number: 1005   Filing as: Single       Number of Withholdings: 7
Pay Type: Hourly        Hours Worked: 37.15     Pay Rate: 20.0  Year To Date: 14
86.0

*/