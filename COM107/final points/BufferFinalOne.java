import java.io.*;
import java.util.*;

public class BufferFinalOne
{
    public static int words, lines, pgraf, curWords, curLB, read;
    public static BufferedReader infile;
    public static PrintWriter outfile;
    public static void main(String[] args) throws IOException    
    {
        initalize();
        while (read != -1)
        {
            while(read != '\u2424')
            {
				if (read == -1)
					break;
                char c = (char)read;
                if (Character.isWhitespace(c))
                    processBlank(c);
                else
                    processText(c);
                System.out.print(c+" ("+read+")");
                read = infile.read();
            }
            updateCount();
        }
        printTotal();
    }
    public static void initalize() throws FileNotFoundException, IOException
    {
        words = 0; lines = 0; pgraf = 0; curWords = 0; curLB=0;
        infile = new BufferedReader(new FileReader("inspectFile.dat"));
        outfile = new PrintWriter("outfile.txt");
        read = infile.read();
    }
    public static void processText(char c)
    {
        if (curLB!=0)
                curLB = 0;
        outfile.append(c);
    }
    public static void processBlank(char c)
    {
        if (curLB!=0)
                curLB = 0;
        outfile.append(c);
        curWords++;
    }
    public static void updateCount()
    {
        if (curLB == 1)
            pgraf++;
        words += curWords;
        curWords = 0;
        lines++;
    }
    public static void printTotal() throws IOException
    {
        System.out.print("words: "+words+" number of lines: "+lines+" paragraphs: "+pgraf);
        infile.close();
        outfile.close();
    }

}
