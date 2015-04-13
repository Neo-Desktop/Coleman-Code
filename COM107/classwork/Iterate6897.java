import javax.swing.*;

public class Iterate6897
{
    public static void main(String[] args) //main
    {
        String input = JOptionPane.showInputDialog("Please enter a large number.");
        //System.out.println("Input Length = "+input.length());
        String sOut ="";
        int i = input.length();
        try
        {
            Long.parseLong(input);
        }
        catch (Exception e)
        {
            JOptionPane.showMessageDialog(null, "Your input \""+input+"\" was invalid."
            , "Fatal Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
        
        while (i > 0)
        {
            char cBuf = input.charAt(i-1);
            sOut += "" + cBuf;
            //System.out.println(i + " - " + cBuf + " - " + sOut);
            i--;
        }
        JOptionPane.showMessageDialog(null, "The digits reversed is: "
                +sOut, "Results", JOptionPane.INFORMATION_MESSAGE);
        System.exit(0);
    }
}
