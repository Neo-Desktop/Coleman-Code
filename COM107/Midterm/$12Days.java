/******************************************************************************
 *     Project: Midterm COM 107                                               *
 *  Class Name: $12Days                                                       *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/06/2012                                                    *
 *       Hours: 1.25 Hours                                                    *
 *     Purpose: Creating an application that exhibit adherence to best        *
 *              programming practices. Effective application documentation,   *
 *              Effective use of whitespace for ease in software maintenance, *
 *              Selection of appropriate data types using meaningful,         *
 *              conventional identifiers, Appropriate use of error handling,  *
 *              Creating simple and complex Boolean expressions to evaluate   *
 *              primitives and strings, Developing a single and dual          *
 *              alternative selection structures and linear selection         *
 *              structures, Using test cases to validate application output.  *
 *                                                                            *
 ******************************************************************************/
 
 import java.util.*;

public class $12Days
{
	public static void main(String[] args) // main
	{
            // english words for possessive numbers.
            String sDay01 = "first", sDay02 = "second", sDay03 = "third",
                    sDay04 = "fourth", sDay05 = "fifth", sDay06 = "sixth",
                    sDay07 = "seventh", sDay08 = "eighth", sDay09 ="nineth",
                    sDay10 = "tenth", sDay11 = "eleventh", sDay12 = "twelfth";
            
            // actual verse.
            String sGift01 = "partridge in a pear tree",
                    sGift02 = "turtle doves", sGift03 = "French hens", 
                    sGift04 = "calling birds", sGift05 = "golden rings",
                    sGift06 = "geese a-laying", sGift07 = "swans a-swimming",
                    sGift08 = "maids a-milking", sGift09 = "ladies dancing",
                    sGift10 = "lords a-leaping", sGift11 = "pipers piping",
                    sGift12 = "drummers drumming";
            
            // first part of verse.
            String sNum01 = "And a ", sNum02 = "Two ", sNum03 = "Three ",
                    sNum04 = "Four ", sNum05 = "Five ", sNum06 = "Six ",
                    sNum07 = "Seven ", sNum08 = "Eight ", sNum09 = "Nine ",
                    sNum10 = "Ten ", sNum11 = "Eleven ", sNum12 = "Twelve ";
            
            //various strings that assisted with my switch structure below below.
            String sSoR01 = "On the ",
                    sSor02 = " day of Christmas,\nmy true love sent to me\n",
                    sFNum01 = "A ", // special case for the first instance of day 1
                    sC = ",\n", // common line break
                    sP = ".", // last line ending
                    sE = "!"; // special case for *very* last line (day 12).
            
            int iDay = 0; // start with an unsupported day, ensures validated input
            
            Scanner console = new Scanner(System.in); // prompt user for input
            System.out.print("What day of Chistmas are we on?\n"
                    + "Please enter the day number.\n"
                    + ":");
            
            String sInput = console.nextLine(); // Grab string input.
            System.out.println(" "); // just for visual appeal.
            try
            {
                iDay = Integer.parseInt(sInput); // see if we can parse an integer
            }
            catch (NumberFormatException ex) // bad input, not a number
            {
                System.out.println("We're sorry, \""+sInput+"\" was an invalid day.\n"
                        + "Please re-run the program.");
                System.exit(1); // error out here. bad input.
            }
            if (iDay <= 0 || iDay > 12) // not a number we support. only days 1-12;
            {
                System.out.println("We're sorry, \""+sInput+"\" was an invalid day.\n"
                        + "Please re-run the program.");
                System.exit(2); // error out here, bad input, unsupported number.
            }
            
            
            //this would be much easier if we knew iteration.
            String sOut = ""; // output buffer.
            switch (iDay)
            {
                case 1:
                    sOut += sSoR01+sDay01+sSor02;
                    sOut += sFNum01+sGift01+sP;
                    break;
                case 2:
                    sOut += sSoR01+sDay02+sSor02;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 3:
                    sOut += sSoR01+sDay03+sSor02;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 4:
                    sOut += sSoR01+sDay04+sSor02;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 5:
                    sOut += sSoR01+sDay05+sSor02;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 6:
                    sOut += sSoR01+sDay06+sSor02;
                    sOut += sNum06+sGift06+sC;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 7:
                    sOut += sSoR01+sDay07+sSor02;
                    sOut += sNum07+sGift07+sC;
                    sOut += sNum06+sGift06+sC;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 8:
                    sOut += sSoR01+sDay08+sSor02;
                    sOut += sNum08+sGift08+sC;
                    sOut += sNum07+sGift07+sC;
                    sOut += sNum06+sGift06+sC;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 9:
                    sOut += sSoR01+sDay09+sSor02;
                    sOut += sNum09+sGift09+sC;
                    sOut += sNum08+sGift08+sC;
                    sOut += sNum07+sGift07+sC;
                    sOut += sNum06+sGift06+sC;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 10:
                    sOut += sSoR01+sDay10+sSor02;
                    sOut += sNum10+sGift10+sC;
                    sOut += sNum09+sGift09+sC;
                    sOut += sNum08+sGift08+sC;
                    sOut += sNum07+sGift07+sC;
                    sOut += sNum06+sGift06+sC;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 11:
                    sOut += sSoR01+sDay11+sSor02;
                    sOut += sNum11+sGift11+sC;
                    sOut += sNum10+sGift10+sC;
                    sOut += sNum09+sGift09+sC;
                    sOut += sNum08+sGift08+sC;
                    sOut += sNum07+sGift07+sC;
                    sOut += sNum06+sGift06+sC;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sP;
                    break;
                case 12:
                    sOut += sSoR01+sDay12+sSor02;
                    sOut += sNum12+sGift12+sC;
                    sOut += sNum11+sGift11+sC;
                    sOut += sNum10+sGift10+sC;
                    sOut += sNum09+sGift09+sC;
                    sOut += sNum08+sGift08+sC;
                    sOut += sNum07+sGift07+sC;
                    sOut += sNum06+sGift06+sC;
                    sOut += sNum05+sGift05+sC;
                    sOut += sNum04+sGift04+sC;
                    sOut += sNum03+sGift03+sC;
                    sOut += sNum02+sGift02+sC;
                    sOut += sNum01+sGift01+sE;
                    break;
            }
            System.out.println(sOut); // print buffer.
            System.exit(0); // we're done.
	}
}

/*Program Output:

S:\programs\Mod1\Midterm>java $12Days
What day of Chistmas are we on?
Please enter the day number.
:11

On the eleventh day of Christmas,
my true love sent to me
Eleven pipers piping,
Ten lords a-leaping,
Nine ladies dancing,
Eight maids a-milking,
Seven swans a-swimming,
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

S:\programs\Mod1\Midterm>java $12Days
What day of Chistmas are we on?
Please enter the day number.
:2

On the second day of Christmas,
my true love sent to me
Two turtle doves,
And a partridge in a pear tree.

S:\programs\Mod1\Midterm>java $12Days
What day of Chistmas are we on?
Please enter the day number.
:invalid input

We're sorry, "invalid input" was an invalid day.
Please re-run the program.

S:\programs\Mod1\Midterm>java $12Days
What day of Chistmas are we on?
Please enter the day number.
:5

On the fifth day of Christmas,
my true love sent to me
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

*/
