/******************************************************************************
 *     Project: Project 3a                                                    *
 *  Class Name: Project3a                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/20/2012                                                    *
 *       Hours: 1.00 Hours                                                    *
 *     Purpose: To demonstrate the ability to create a conventionally named   *
 *              java application, the parsing of numeric strings with         *
 *              exception handling, format numeric output using Decimal       *
 *              Format, write to and read from a simple text file, use Decimal*
 *              Format to format output                                       *
 *                                                                            *
 ******************************************************************************/
 
public class Project3a
{
	public static void main(String[] args) // main
	{
	int iNum01 = 1337; //1a
	int iNum02 = 42; //1a
	
        double dPow  = Math.pow(iNum01, iNum02); //1b1
        double dSqrt = Math.sqrt(iNum01); //1b2
        
        System.out.println("The first number is: "+iNum01+".");
        System.out.println("The second number is: "+iNum02+".");
        System.out.println(""+iNum01+" raised to the power of "+iNum02+" is: "
                + dPow+"."); //1b1
        System.out.println("The square root of "+iNum01+" is: "+dSqrt+".\n");//1b2
        
        if (dPow >= dSqrt) //1b3
        {
            System.out.println("The first number ("+iNum01+") raised to the "
                    +"second number ("+iNum02+") \nis greater than the square "
                    +"root of ("+iNum01+")."); //1b3
        }
        else
        {
            System.out.println("The square root of "+iNum01+" is greater than"
                    + "the first number("+iNum01+") raised to the second number"
                    + "("+iNum02+")."); //1b3
        }
        System.out.println("\n---------------------------------------------\n");
        
        double dRad = 7; //1b4
        double dDia = 7*2; //1b4
        double dArea = Math.PI*(Math.pow(dRad, 2)); //1b4
        
        System.out.println("Circle's Radius: "+ dRad + "."); //1b4
        System.out.println("Circle's Diameter: " + dDia + "."); //1b4
        System.out.println("Circle's Area: "+ dArea + "."); //1b4
        
	System.out.println("\n---------------------------------------------\n");
        
        String sQuote= "Now is the time for all good men to come to the aid of "
                + "their country."; //1c
        
        System.out.println("The ammount of characters in the quote \n"
                + "\""+sQuote+"\" \nis: "+sQuote.length()+".\n"); //1c1
        
        System.out.println("The same quote in all caps is: \n"
                + "\""+sQuote.toUpperCase()+"\"\n"); //1c2
        
        System.out.println("The same quote in lower case is: \n"
                + "\""+sQuote.toLowerCase()+"\"\n"); //1c3
        
        System.out.println("The first index of the character 'o' is: "
                + sQuote.indexOf('o')+"\n"); //1c4
        
        System.out.println("The next index of the character 'o' is: "
                + sQuote.indexOf('o',(sQuote.indexOf('o')+1))+"\n"); //1c5
        
        System.out.println("The character present at index 17 is a(n) '"
                + sQuote.charAt(17) + "'.\n"); //1c6
        
        String sSubstr = sQuote.substring(sQuote.indexOf('t'),
                (sQuote.length()-1)); //1c7
        
        System.out.println("The substring of the quote from the first instence "
                + "of the character 't' \nto the last character, not including "
                + "a period is: \n\""+sSubstr+"\""); //1c8
	}
}

/* output:
    E:\programs\Mod1\Project3>java Project3a
    The first number is: 1337.
    The second number is: 42.
    1337 raised to the power of 42 is: 1.983896928320167E131.
    The square root of 1337 is: 36.565010597564445.

    The first number (1337) raised to the second number (42)
    is greater than the square root of (1337).

    ---------------------------------------------

    Circle's Radius: 7.0.
    Circle's Diameter: 14.0.
    Circle's Area: 153.93804002589985.

    ---------------------------------------------

    The ammount of characters in the quote
    "Now is the time for all good men to come to the aid of their country."
    is: 69.

    The same quote in all caps is:
    "NOW IS THE TIME FOR ALL GOOD MEN TO COME TO THE AID OF THEIR COUNTRY."

    The same quote in lower case is:
    "now is the time for all good men to come to the aid of their country."

    The first index of the character 'o' is: 1

    The next index of the character 'o' is: 17

    The character present at index 17 is a(n) 'o'.

    The substring of the quote from the first instence of the character 't'
    to the last character, not including a period is:
    "the time for all good men to come to the aid of their country"
*/