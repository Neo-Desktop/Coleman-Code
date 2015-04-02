// Amrit Panesar
// 10/01/2012
// Classwork #10 Page 618 Malik.

public class Classwork10
{
    public static void main(String[] args) //main
    {
		int[][] alpha = new int[10][20]; //a
		
		for(int[] row : alpha)
		{
			for (int coloumn : row)
			{
				coloumn = 5; //b
			}
		}
		
		boolean bset = true;
		for (int[] row : alpha)
		{
			for (int coloumn : row)
			{
				if (bset)
					coloumn = 1; //c
				else
					coloumn = 2; //c
			}
				bset = false;
		}
		
		int curRow = 0;
		int curCol = 1;
		alpha[0][0] = 5;
		for (int i=1; i<(10*20)-1; i++)
		{
			if (curCol == 20)
			{
				curCol = 0;
				curRow++;
			}
			if (curCol == 0)
			{
				alpha[curRow][curCol] = alpha[curRow-1][19] *2; //d
			}
			else
			{
				alpha[curRow][curCol] = alpha[curRow][curCol-1] *2; //d
			}
			curCol++;
		}
		
		for (int[] row : alpha)
		{
			for (int coloumn : row)
			{
				System.out.print(coloumn + ' '); //e
			}
			System.out.println(); //e
		}
		
		for (int[] row : alpha)
		{
			for (int coloumn : row)
			{
				System.out.println(coloumn + ' '); //f
			}
		}
	}
}