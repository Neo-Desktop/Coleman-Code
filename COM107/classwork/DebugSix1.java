public class DebugSix1
// Start with a penny
// Double it every day
// How much do you have in a month?
{
   public static void main(String[] args)
   {
     double money = 0.01;
     int day = 1;
     while(day <= 31)
     {
      money = 2 * money;
      System.out.println("After day " + day +
         " you have " + money);
		day++;
    }
   }
}