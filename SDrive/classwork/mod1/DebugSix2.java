public class DebugSix2
// Print the character values
// of 65 through 122
{
   public static void main(String[] args)
   {
     char letter;
     int a = 0;
     for(a = 65; a <= 122; a++)
       {
       letter = (char)a;
       System.out.print("  " + letter);
       if(a == 85 || a == 105)
         System.out.println();
     }


     System.out.println("\nEnd of program");

    }

}