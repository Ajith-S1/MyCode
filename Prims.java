import java.util.Scanner;
// prims long ver 1
public class Prims {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n,i,j;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter order of matrix");
		n=sc.nextInt();
		int cost[][]=new int[n][n];
		System.out.println("Enter cost matrix");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cost[i][j]=sc.nextInt();
			}
		}
		prims(n,cost);
	}
	static void prims(int n,int a[][])
	{
		int i,j,u,v,min,sum,k;
		int p[]=new int[n];
		int d[]=new int[n];
		int s[]=new int[n];
		int t[][]=new int[n][n];
		int src=0;
		min=999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]!=0 && a[i][j]<=min)
				{
					min=a[i][j];
					u=i;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			d[i]=a[src][i];
			s[i]=0;
			p[i]=src;
		}
		s[src]=1;
		sum=0;		k=0;
		for(i=1;i<n;i++)
		{
			min=999;
			u=-1;
			for(j=0;j<n;j++)
			{
				if(s[j]==0)
				{
					if(d[j]<=min)
					{
						min=d[j];
						u=j;
					}
				}
			}
			t[k][0]=u;
			t[k][1]=p[u];
			k++;
			sum+=a[u][p[u]];
			s[u]=1;
			for(v=0;v<n;v++)
			{
				if(s[v]==0 && a[u][v]<d[v])
				{
					d[v]=a[u][v];
					p[v]=u;
				}
			}
		}
		if(sum>=999)
		{
			System.out.println("Spanning tree does not exist ");
		}
		else
		{
			System.out.println("Spanning tree exist and min spannig tree is\n");
			for(i=0;i<n-1;i++)
			{
				System.out.println(t[i][0]+" "+t[i][1]);
			}
			System.out.println("cost of spanning tree "+sum);
		}
	}
}

