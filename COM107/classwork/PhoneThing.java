/******************************************************************************
 *  Class Name: PhoneThing                                                    *
 *      Author: Amrit Panesar -ASP ,o/                                        *
 * Last Edited: 09/12/2012                                                    *
 *     Purpose: Takes input from a user in the form of a phone number,        *
 *              validate input, convert from number to letters, allow numbers *
 *              from input to pass-thru, and ignore any whitespace/special    *
 *              characters from user input.                                   *
 ******************************************************************************/

import javax.swing.*;

public class PhoneThing
{
    public static void main(String[] args) //main
    {
        String sN00="", sN01="", sN02="abc", sN03="def", sN04="ghi",
                sN05="jkl", sN06="mno", sN07="pqrs", sN08="tuv", sN09="wxyz";
        boolean quest = false;
        while (true)
        {
            if (quest)
            {
                int ret = JOptionPane.showConfirmDialog(null, "Do you wish to continue?",
                    "Question", JOptionPane.YES_NO_OPTION);
                if ( ret == JOptionPane.NO_OPTION || ret == JOptionPane.CLOSED_OPTION)
                    System.exit(0);
            }
            String input = "";
            try
            {
                   input = JOptionPane.showInputDialog("Please enter a phone number.");
                   input = input.toLowerCase();
            }
            catch (Exception e)
            {
                System.exit(0);
            }

            String sOut ="";
            
            if (input.length() < 8)
            {
                JOptionPane.showMessageDialog(null, "The phone number: \""
                        +input+"\" was not long enough",
                        "Error", JOptionPane.ERROR_MESSAGE);
                quest = true;
                continue;
            }

            for (int i=0;i<=input.length()-1;i++)
            {
                char cBuf = input.charAt(i);
                if(Character.isDigit(cBuf))
                {
                    sOut += cBuf;
                    continue;
                }
                for (int j=0;j<=9;j++)
                {
                    switch(j)
                    {
                        case 0:
                            for(int k=0;k<=sN00.length()-1;k++)
                            {
                                if(sN00.charAt(k)==cBuf)
                                    sOut += "0";
                            }
                            break;
                        case 1:
                            for(int k=0;k<=sN01.length()-1;k++)
                            {
                                if(sN01.charAt(k)==cBuf)
                                    sOut += "1";
                            }
                            break;
                        case 2:
                            for(int k=0;k<=sN02.length()-1;k++)
                            {
                                if(sN02.charAt(k)==cBuf)
                                    sOut += "2";
                            }
                            break;
                        case 3:
                            for(int k=0;k<=sN03.length()-1;k++)
                            {
                                if(sN03.charAt(k)==cBuf)
                                    sOut += "3";
                            }
                            break;
                        case 4:
                            for(int k=0;k<=sN04.length()-1;k++)
                            {
                                if(sN04.charAt(k)==cBuf)
                                    sOut += "4";
                            }
                            break;
                        case 5:
                            for(int k=0;k<=sN05.length()-1;k++)
                            {
                                if(sN05.charAt(k)==cBuf)
                                    sOut += "5";
                            }
                            break;
                        case 6:
                            for(int k=0;k<=sN06.length()-1;k++)
                            {
                                if(sN06.charAt(k)==cBuf)
                                    sOut += "6";
                            }
                            break;
                        case 7:
                            for(int k=0;k<=sN07.length()-1;k++)
                            {
                                if(sN07.charAt(k)==cBuf)
                                    sOut += "7";
                            }
                            break;
                        case 8:
                            for(int k=0;k<=sN08.length()-1;k++)
                            {
                                if(sN08.charAt(k)==cBuf)
                                    sOut += "8";
                            }
                            break;
                        case 9:
                            for(int k=0;k<=sN09.length()-1;k++)
                            {
                                if(sN09.charAt(k)==cBuf)
                                    sOut += "9";
                            }
                            break;
                        default:
                        {
                            System.out.println("ILLOGICAL!?");
                            System.exit(1);
                        }
                    }
                }
            }
            String sOutput = "";
            for(int i=0;i<=sOut.length()-1;i++)
            {
                if (i <= 6)
                {
                    if (i == 3)
                    {
                        sOutput += "-";
                    }
                    sOutput += sOut.charAt(i);
                }
            }
            JOptionPane.showMessageDialog(null, "The converted phone number is: "
                    +sOutput, "Results", JOptionPane.INFORMATION_MESSAGE);
            quest = true;
        }
    }
}
