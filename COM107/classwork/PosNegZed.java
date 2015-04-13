import javax.swing.*;

public class PosNegZed
{
    public static void main(String[] args) //main
    {
        String input = JOptionPane.showInputDialog("Please enter a whole number.");
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
		if (iInt01 > 0)
		{
			JOptionPane.showMessageDialog(null, "\""+input+"\" is positive.",
			"Thank You", JOptionPane.INFORMATION_MESSAGE);
		}
		else if (iInt01 < 0)
		{
			JOptionPane.showMessageDialog(null, "\""+input+"\" is negative.",
			"Thank You", JOptionPane.INFORMATION_MESSAGE);
		}
		else if (iInt01 == 0)
		{
			JOptionPane.showMessageDialog(null, "\""+input+"\" is zero.",
			"Thank You", JOptionPane.INFORMATION_MESSAGE);
		}
		System.exit(0);
		
	}
}