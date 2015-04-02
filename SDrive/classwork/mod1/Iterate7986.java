import javax.swing.*;

public class Iterate7986
{
    public static void main(String[] args) //main
    {
        String input = JOptionPane.showInputDialog("Please enter a large number.");
        int iInt01 = 0;
        String sOut = "";
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
        for (int i=0;i<=input.length()-1;i++)
        {
            char cBuf = input.charAt(i);
            sOut += cBuf + " ";
            iInt01 += Character.getNumericValue(cBuf);
            //System.out.println(cBuf + " - " + iInt01);
        }
        JOptionPane.showMessageDialog(null, "The summation of the digits is: "
                +iInt01 + "\n" + sOut, "Results", JOptionPane.INFORMATION_MESSAGE);
        System.exit(0);
    }
}
