
public class Fcycle {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int V=4,E=4;
		Graph graph= new Graph(V,E);
		graph.edge[0].src = 0;
		graph.edge[0].src = 1;	
		graph.edge[1].src = 1;
		graph.edge[1].src = 2;	
		graph.edge[2].src = 2;
		graph.edge[2].src = 0;	
		
		if(graph.iscycle()==1)
			System.out.println("Cycle");
		else System.out.println("NO cycle");
	}

}

class Graph
{
	int V,E;
	
	class Edge 
	{
		int src,dst;
	}
	
	Edge edge[];
	Graph(int v,int e)
	{
		V=v;
		E=e;
		edge=new Edge[E];
		for(int i=0;i<E;i++)
			edge[i]= new Edge();
	}
	
	int find(int p[],int i)
	{
		if(p[i]==-1)
			return i;
		return find(p,p[i]);
	}
	void union(int p[],int a,int b)
	{
		p[a]=b;
	}
	int iscycle()
	{
		int parent[] = new int[V];
		
		for(int i=0;i<V;i++)
		{
			parent[i]=-1;
		}
		
		for(int i=0;i<V;i++)
		{
			int x=find(parent,edge[i].src);
			int y=find(parent,edge[i].dst);
			if(x==y)
				return 1;
			union(parent,x,y);
		}
		return 0;
	}
}
