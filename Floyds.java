import java.util.Scanner;

public class Floyds {
	
	static void floyds(short a[][],int n)
	{
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(a[i][k]+a[k][j] < a[i][j])
						a[i][j] = (short) (a[i][k] + a[k][j]);
				
	}
	
	static void display(short a[][],int n)
	{
		System.out.println("new cost matrix : ");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				System.out.print(a[i][j] + " ");
			System.out.println();
		}
			
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter no of vertex");
		int n=sc.nextInt();
		short costm[][]= new short[n][n];
		
		System.out.println("Enter cost matrix");
		for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					costm[i][j]= sc.nextShort();
		floyds(costm,n);
		display(costm,n);
		sc.close();
	}

}

