import javax.swing.*;

public class FooTax
{

    public static void main(String[] args) //main
    {
            String sMarriage = JOptionPane.showInputDialog("Are you (S)ingle, (M)arried, or (H)ead of Houshold");
            char cSel = sMarriage.toLowerCase().charAt(0);
            double dStdDeduct = 0.00;
            if (cSel == 's')
                dStdDeduct = 157.00;
            else if (cSel == 'h')
                dStdDeduct = 314.00;
            else
            {
                // assume married.
                String sWitholding = JOptionPane.showInputDialog("How many depedendant allowances do you claim?\n(Please enter a number)");
                int iWithholdings = Integer.parseInt(sWitholding);
                if (iWithholdings < 2)
                    dStdDeduct = 157.00;
                else
                    dStdDeduct = 314.00;
            }
            JOptionPane.showMessageDialog(null,
                    "Your Standard Deduction is: "+dStdDeduct, //message
                    "Thank You", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
            String sExemptions = JOptionPane.showInputDialog("How many exemption allowances do you claim?\n(Please enter a number)");
            int iExemptions = 0;
            try
            {
                iExemptions = Integer.parseInt(sExemptions);
            }
            catch(Exception e)
            {
                JOptionPane.showMessageDialog(null,
                    "Your input was incorrect, please re-run the program", //message
                    "Fatal Error", //title
                    JOptionPane.ERROR_MESSAGE//type
                    );
                return;
            }
            double dExeDeduct = 0.00;
            switch (iExemptions)
            {
                case 0:
                    dExeDeduct = 0.00;
                    break;
                case 1:
                    dExeDeduct = 4.68;
                    break;
                case 2:
                    dExeDeduct = 9.35;
                    break;
                case 3:
                    dExeDeduct = 14.03;
                    break;
                case 4:
                    dExeDeduct = 18.70;
                    break;
                case 5:
                    dExeDeduct = 23.38;
                    break;
                case 6:
                    dExeDeduct = 28.05;
                    break;
                case 7:
                    dExeDeduct = 32.73;
                    break;
                case 8:
                    dExeDeduct = 37.40;
                    break;
                case 9:
                    dExeDeduct = 42.08;
                    break;
                case 10:
                    dExeDeduct = 46.75;
                    break;
                default:
                    dExeDeduct = (4.68 * iExemptions);
                    break;
            }
            JOptionPane.showMessageDialog(null,
                    "Your exemption allowance is: "+dExeDeduct, //message
                    "Thank You", //title
                    JOptionPane.INFORMATION_MESSAGE //type
                    );
            
    }
	
}