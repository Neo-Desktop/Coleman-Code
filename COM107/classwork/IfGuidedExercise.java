import javax.swing.*;

public class IfGuidedExercise
{

    public static void main(String[] args) //main
    {
        String sInput = JOptionPane.showInputDialog("Please enter a phrase.");
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
        if (iInt01 == 7) 
        {
            JOptionPane.showMessageDialog(null,
                    "Thank You for inputting a 7", //message
                    "Thank You", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
        }
        if (iInt01 < 0)
        {
            JOptionPane.showMessageDialog(null,
                    "Thank You for inputting a negative number", //message
                    "Thank You", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
        }
        else 
        {
            JOptionPane.showMessageDialog(null,
                    "Thank You for inputting a positive number", //message
                    "Thank You", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
        }
        if (iInt01 >= 5 && iInt01 <= 10)
        {
            JOptionPane.showMessageDialog(null,
                    "Thank You for inputting "+iInt01+", its square is: "+
                    Math.pow(iInt01,2), //message
                    "Thank You", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
        }
        if (sInput.equals("Green") && iInt01 == 7)
        {
            JOptionPane.showMessageDialog(null,
                    "Congradulations on your achievement!",
                    "A winner is you!", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
        }
        else
        {
            JOptionPane.showMessageDialog(null,
                    "Better luck next time.",
                    "Failure", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
        }
        if ((sInput.equals("White") && iInt01 == 10) ||
                (sInput.equals("Blue") && iInt01 == 11) ||
                (sInput.equals("Red")))
        {
            JOptionPane.showMessageDialog(null,
                    "Great color choice",
                    "Fabulous", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
        }
        else
        {
            JOptionPane.showMessageDialog(null,
                    "The color choice and number are not a pair.",
                    "Not so Fabulous", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
            
        }
        
    }

}