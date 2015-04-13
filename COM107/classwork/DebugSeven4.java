public class DebugSeven4
{
  public static void main(String[] args)
  {
    String aString = "The sly brown fox jumped over the lazy dog";

    int numLetters = 0;
    int stringLength = aString.length();

    for(int i=0; i < stringLength; i++)
    {
      char ch = Character.toLowerCase(aString.charAt(i));

      if(Character.isLetter(ch))
      numLetters++;
    }
    System.out.println("The number of letters is " + numLetters);
  }
}