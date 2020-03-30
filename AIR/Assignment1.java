import java.util.Scanner ;
public class Assignment1 {
	Scanner S = new Scanner(System.in);
	public int[][] board = new int[3][3];
	public int[][] fx = new int[3][3];
	
	
	public void init()
	{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				board[i][j] = 0;
				fx[i][j] = 0;
			}
	}
	
	public void accept()
	{
		for(int i = 0;i < 3; i++)
			for(int j=0; j < 3; j++)
				board[i][j] = S.nextInt();
	}	
	public void display()
	{
		for(int i = 0; i < 3; i++)
		{		
			for(int j = 0; j < 3; j++)
			{
				if(board[i][j] == 1)
					System.out.print("O" + " ");
				else if(board[i][j] == 2)
					System.out.print("X" + " ");
				else
					System.out.print("-" + " ");		
			}
			System.out.print("\n");
		}
	}
	
	public int yourMOve()
	{
		int flag = 0;
		while(flag == 0)
		{
			System.out.print("Enter the Positiopn for Your move:(i,j) ");
			int i = S.nextInt();
			int j = S.nextInt();
			
			if(board[i][j] != 0)
				System.out.println("Invalid Move");
			else
			{
				board[i][j] = 1;
				flag = 1;
			}	
		}
		return	WinCondition(1);
	}
	public int compMOve()
	{
		int flag = 0;
		System.out.println("Comp move:  ");
		A_Star();
		//Checking for nearest winning condition
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(fx[i][j] > 0)
				{
					if(board[i][j] == 0)
					{
						board[i][j] = 2;
						flag = 1;
						break;	
					}
				}
			}
			if(flag == 1)
				break;
			
		}
		//Otherwise finding the next empty location
		if(flag == 0)
		{
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					if(board[i][j] == 0)
					{
						board[i][j] = 2;
						flag = 1;
						break;	
					}
				}
				if(flag == 1)
					break;
			
			}
			
		}	
		return	WinCondition(2);
	}
	public int WinCondition(int p)
	{		
		for(int i=0; i < 3; i++)
		{
			//winning conditiohn for row
			if(board[0][i] == p && board[1][i] == p && board[2][i] == p)		
				return 0;
			//winning conditiohn for coloumn
			if(board[i][0] == p && board[i][1] == p && board[i][2] == p)		
				return 0;
		}
			if(board[0][0] == p && board[1][1] == p && board[2][2] == p)
				return 0;
			if(board[0][2] == p && board[1][1] == p && board[2][0] == p)
				return 0;
			return 1;
	}
	
	public void A_Star()
	{		
		for(int i=0; i < 3; i++)
		{
			// For Rows
			if(board[i][0] == 1 && board[i][1] == 1)		
				fx[i][2] = fx[i][2] + 1;

			if(board[i][1] == 1 && board[i][2] == 1)		
				fx[i][0] = fx[i][0] + 1;

			if(board[i][0] == 1 && board[i][2] == 1)		
				fx[i][1] = fx[i][1] + 1;

			// For coloumns
			if(board[0][i] == 1 && board[1][i] == 1)		
				fx[2][i] = fx[2][i] + 1;

			if(board[1][i] == 1 && board[2][i] == 1)		
				fx[0][i] = fx[0][i]  + 1;

			if(board[0][i] == 1 && board[2][i] == 1)		
				fx[1][i] = fx[1][i] + 1;
		}
		
		// For diagonals
			
		if(board[0][0] == 1 && board[1][1] == 1)		
				fx[2][2] = fx[2][2] + 1;

			if(board[1][1] == 1 && board[2][2] == 1)		
				fx[0][0] =fx[0][0] + 1;

			if(board[0][0] == 1 && board[2][2] == 1)		
				fx[1][1] =fx[1][1] + 1;

			
			if(board[0][2] == 1 && board[1][1] == 1)		
				fx[2][0] = fx[2][0] + 1;

			if(board[1][1] == 1 && board[2][0] == 1)		
				fx[0][2] = fx[0][2] + 1;

			if(board[0][2] == 1 && board[2][0] == 1)		
				fx[1][1] = fx[1][1] + 1;

			/*System.out.println("Heuristic Values of Borad are: ");	
			for(int i = 0; i < 3; i++)
			{		
				for(int j = 0; j < 3; j++)
				{
					System.out.print(fx[i][j]+" ");		
				}
				System.out.print("\n");
			}*/
	}
	public static void main(String []args){

	Assignment1 A = new Assignment1();
	
	A.init();
	A.display();
	System.out.println("Enter the move values ");
	
	int flag = 0, count = 0;
	while(flag == 0)
	{
		int y = A.yourMOve();
		count++;
		A.display();
		if(y == 0)
		{
			System.out.println("You Won");
			flag = 1;
			break;
		}
		int c = A.compMOve();
		count++;
		A.display();
		if(c == 0)
		{
			System.out.println("Computer Won");
			flag = 1;
			break;
		}
		if(count >= 8)
		{
			System.out.println("Well Tried!! Match Is Draw...");
			break;
		}
	}
				
   }
}
