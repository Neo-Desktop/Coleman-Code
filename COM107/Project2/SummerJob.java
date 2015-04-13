/******************************************************************************
 *     Project: Project 2b                                                    *
 *  Class Name: SummerJob                                                     *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 08/23/2012                                                    *
 *       Hours: 0.50 Hours                                                    *
 *     Purpose: To calculate the gross and net pay of a hypothetical summer   *
 *              job. The ability to deduct taxes is also demonstrated.        *
 ******************************************************************************/
 
 import java.util.*;
 
 public class SummerJob
{
	public static void main(String[] args) // main
	{
		final double HOURLY_WAGE	= 15.50;// hourly wage
		final double PARENT_RATE	= 0.50; // 50 cents per every *whole* dollar made.
		final double TAX_RATE		= 0.14; // 14% taxes withheld
		final double CLOTHING_RATE	= 0.10; // 10% for clothing
		final double SCHOOL_RATE	= 0.01; // 01% for school supplies
		final double SAVINGS_RATE	= 0.25; // 25% for savings bond purchase
		double dHoursWorked	= 0.0;
		
		//PROMPT for input of hours worked
		try
			{
				Scanner console = new Scanner(System.in);
				System.out.print("Please enter the ammount of hours worked: ");
				//STORE hours worked
				dHoursWorked = console.nextDouble();
			}
		catch (Exception e)
			{
				System.out.println("We're sorry, that was an invalid value.\n"
					+ "Please re-run the program.");
				return;
			}
			//CALCULATE gross pay
				//grossPay = hours * rate	
		double dGrossPay	= (dHoursWorked * HOURLY_WAGE);
			//CALCULATE tax
				//Tax = gross * .14
		double dTaxes		= (dGrossPay * TAX_RATE);
			//CALCULATE net pay
				//netPay = gross – taxes
		double dNetPay		= (dGrossPay - dTaxes);
			//CALCULATE clothing expense
				//clothing = netPay * .10
		double dCloExp		= (dNetPay * CLOTHING_RATE);
			//CALCULATE school supply expense
				//supplies = netPay * .01
		double dSchExp		= (dNetPay * SCHOOL_RATE);
			//CALCULATE remainder
				//remainder = netPay – clothing – supplies
		double dEODBal		= (dNetPay - dCloExp - dSchExp);
			//CALCULATE student savings
				//studentSavings = remainder * .25
		double dSavBon		= (int)(dEODBal * SAVINGS_RATE);
			//CALCULATE parental savings
				//Parental savings = student Savings * .5
		double dParSav		= (dSavBon * PARENT_RATE);
		double dGTotal		= (dEODBal + dSavBon + dParSav);
		
		// System.out.format("%.2f", 10.499);
			//DISPLAY pay rate
		System.out.format("Your pay rate is: $%.2f per hour\n", dHourlyWage); // pay rate
			//DISPLAY hours
		System.out.format("You worked: %.2f hours\n", dHoursWorked); // hours
			//DISPLAY gross pay
		System.out.format("Your taxable income is: $%.2f\n", dGrossPay); // gross pay
			//DISPLAY taxes
		System.out.format("Taxes taken from your paycheck: $%.2f\n",dTaxes); // taxes
			//DISPLAY net pay
		System.out.format("Earning you a total of: $%.2f\n", dNetPay); // net pay
		System.out.format("------------------------------------------------------\n");
			//DISPLAY clothing expense
		System.out.format("Your withholdings for clothes expenses are: $%.2f\n", dCloExp);
			//DISPLAY supply expense
		System.out.format("Your withholdings for school supplies are: $%.2f\n", dSchExp);
			//DISPLAY student savings
		System.out.format("Your withholdings for a saving bond are: $%.2f\n", dSavBon);
		System.out.format("------------------------------------------------------\n");
			//DISPLAY parental savings
		System.out.format("Your parental contributions for this month are: $%.2f\n", dParSav);
		System.out.format("Giving you a grand total of: %.2f\n", dGTotal);
	}
}
/* Output:
	E:\programs\Mod1\Project2>java SummerJob
	Please enter the ammount of hours worked: 10
	Your pay rate is: $15.50 per hour
	You worked: 10.00 hours
	Your taxable income is: $155.00
	Taxes taken from your paycheck: $21.70
	Earning you a total of: $133.30
	------------------------------------------------------
	Your withholdings for clothes expenses are: $13.33
	Your withholdings for school supplies are: $1.33
	Your withholdings for a saving bond are: $29.00
	------------------------------------------------------
	Your parental contributions for this month are: $14.50
	Giving you a grand total of: 162.14

	E:\programs\Mod1\Project2>java SummerJob
	Please enter the ammount of hours worked: 20
	Your pay rate is: $15.50 per hour
	You worked: 20.00 hours
	Your taxable income is: $310.00
	Taxes taken from your paycheck: $43.40
	Earning you a total of: $266.60
	------------------------------------------------------
	Your withholdings for clothes expenses are: $26.66
	Your withholdings for school supplies are: $2.67
	Your withholdings for a saving bond are: $59.00
	------------------------------------------------------
	Your parental contributions for this month are: $29.50
	Giving you a grand total of: 325.77

	E:\programs\Mod1\Project2>java SummerJob
	Please enter the ammount of hours worked: 40
	Your pay rate is: $15.50 per hour
	You worked: 40.00 hours
	Your taxable income is: $620.00
	Taxes taken from your paycheck: $86.80
	Earning you a total of: $533.20
	------------------------------------------------------
	Your withholdings for clothes expenses are: $53.32
	Your withholdings for school supplies are: $5.33
	Your withholdings for a saving bond are: $118.00
	------------------------------------------------------
	Your parental contributions for this month are: $59.00
	Giving you a grand total of: 651.55
*/