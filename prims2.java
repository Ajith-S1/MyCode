import java.util.Scanner;

public class Prims2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter no of vertex");
		int n=sc.nextInt();
		int costm[][]=new int [n][n];
		boolean visited[]=new boolean[n];
		System.out.println("Enter cost matrix");
		for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					costm[i][j]=sc.nextInt();
		for(int i=0;i<n;i++)
			visited[i]=false;
		System.out.println("Enter source");
		int src = sc.nextInt();
		visited[src-1]=true;
		int source=0,target=0,cost=0;
		for(int i=1;i<n;i++)
		{
			int min= Integer.MAX_VALUE;
			for(int j=0;j<n;j++)
			{
				if(visited[j])
				{
					for(int k=0;k<n;k++)
					{
						if(!visited[k] && min>costm[j][k])
						{
							min = costm[j][k];
							source = j;
							target = k;
						}
					}
				}
			}
			visited[target]=true;
			System.out.println("( "+(source+1)+" -> "+(target+1)+ " )");
			cost+=min;
		}
		
		System.out.println("min cost of spanning tree "+cost);
		sc.close();
	}

}

