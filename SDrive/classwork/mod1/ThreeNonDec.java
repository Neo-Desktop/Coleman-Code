import javax.swing.*;

public class ThreeNonDec
{
    public static void main(String[] args) //main
    {
        String input = JOptionPane.showInputDialog("Please enter a first whole number.");
        int iInt01 = 0;
        try
        {
            iInt01 = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
		input = JOptionPane.showInputDialog("Please enter a second whole number.");
        int iInt02 = 0;
        try
        {
            iInt02 = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
		input = JOptionPane.showInputDialog("Please enter a third whole number.");
        int iInt03 = 0;
        try
        {
            iInt03 = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "We're sorry, \""+input+"\" was"
                  + " an incorrect input.", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(0);
        }
		
		String output = "";
		if (iInt01 >= iInt02 && iInt02 >= iInt03)
			output += "" + iInt03 + ", " + iInt02 + ", " + iInt01;
		else if (iInt01 >= iInt02 || iInt02 <= iInt03)
		{
			if (iInt01 >= iInt03)
				output += "" + iInt02 + ", " + iInt03 + ", " + iInt01;
			else 
				output += "" + iInt02 + ", " + iInt01 + ", " + iInt03;
		}
		else if (iInt01 <= iInt02 || iInt02 >= iInt03)
		{
			if (iInt02 <= iInt03)
				output += "" + iInt02 + ", " + iInt03 + ", " + iInt01;
			else 
				output += "" + iInt02 + ", " + iInt01 + ", " + iInt03;
		}

		JOptionPane.showMessageDialog(null, "Your numbers in nondecending order is:\n\""+output+"\"",
			"Thank You", JOptionPane.INFORMATION_MESSAGE);
        System.exit(0);	
	}
}

















