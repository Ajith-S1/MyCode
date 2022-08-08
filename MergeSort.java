import java.util.Random;
import java.util.Scanner;

public class Main {
	
	static int[] merge(int a[],int low,int mid,int high)
	{
			int res[]= new int[high-low];
			int i=low,j=mid+1,k=low;
			while(i<=mid  &&  j<=high)
			{
				if(a[i]<a[j])
				{
					res[k++]=a[i++];
				}
				else res[k++]=a[j++];
			}
			
			while(i<=mid)
				res[k++]=a[i++];
			while(j<=high)
				res[k++]=a[j++];
			return res;
	}
	
	 static void mergeS(int a[],int low,int high)
	{
		if(low>high)
		{
			int mid= (low+high)/2;
			mergeS(a,low,mid);
			mergeS(a,mid+1,high);
			a =merge(a,low,mid,high);
		}
	}

	public static void main(String[] args) {
		Scanner scan= new Scanner(System.in);
		Random ran= new Random();
		long start,stop;
		System.out.println("Enter choice\n1:Best case");
		System.out.println("2:Avg case\n3:worst case");
		int ch;
		ch= scan.nextInt();
		int n=0;
		int[] a=null;
			switch(ch)
			{
				 
				case 1 : System.out.println("Best case\nEnter n");
								n= scan.nextInt();
								a=new int[n];
								for(int i=0;i<n;i++)
										a[i]=i;
								break;
				case 2 : System.out.println("Avg case\nEnter n");
							  n= scan.nextInt();
							  a=new int[n];
							//  int[] b=new int[n] ;
								for(int i=0;i<n;i++)
										a[i]=ran.nextInt();
								break;
				case 3 : System.out.println("Worst case\nEnter n");
							  n= scan.nextInt();
							  a=new int[n];
							//  int[] c=new int[n] ;
								for(int i=0;i<n;i++)
										a[i]=n-i;
								break;
				
			}
			scan.close();
			start = System.nanoTime();
			mergeS(a,(int)0,n-1);
			stop=System.nanoTime();
			System.out.println("Time taken to sort "+a.length+" array : "+(stop-start)+" ns");
	}
	
}


