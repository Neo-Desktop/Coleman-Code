/******************************************************************************
 *     Project: Project 3b                                                    *
 *  Class Name: DecFormat                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/20/2012                                                    *
 *       Hours: 0.25 Hours                                                    *
 *     Purpose: To demonstrate the ability to create a conventionally named   *
 *              java application, the parsing of numeric strings with         *
 *              exception handling, format numeric output using Decimal       *
 *              Format, write to and read from a simple text file, use Decimal*
 *              Format to format output                                       *
 *                                                                            *
 ******************************************************************************/

import java.text.DecimalFormat;

public class DecFormat
{
	public static void main(String[] args) // main
	{
            DecimalFormat df3Pos = new DecimalFormat("#####,00.000"); //2a
            DecimalFormat df5Pos = new DecimalFormat("#######,00.0000"); //2b
            
            double dLarge01 = 0.1535012260547;
            
            System.out.println("dLarge01 formatted to 3 places: "
                    + df3Pos.format(dLarge01)); //2c
            
            System.out.println("dLarge01 formatted to 5 places: "
                    + df5Pos.format(dLarge01)); //2c
	}
}
/* output:
E:\programs\Mod1\Project3>java DecFormat
dLarge01 formatted to 3 places: 00.154
dLarge01 formatted to 5 places: 00.1535
 */