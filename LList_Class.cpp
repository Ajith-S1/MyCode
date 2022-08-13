#include<iostream>

using namespace std;
#define MAX 15

struct node
{
	int data;
	node *link;
};


class list
{
private : node *first;
public: list()
	{
		first=00;
		cout<<"Inside ZPC\n";
	}
	~list();
	list(const list &);
	void insert_F();
	void insert_R(int d);
	void delete_R();
	void delete_F();
	void display()const;
	
};

void list::insert_F()
{
	node * t= new node;
	cout<<"Enter the data\n";
	cin>>(t->data);
	(t->link) =0;
	if(first ==0)
	{
		first=t;
		return;
	}
	t->link=first;
	first =t;
}

void list::insert_R(int d)
{
	node * t= new node;
	//cout<<"Enter the data\n";
	//cin>>(t->data);
	(t->data) = d;
	(t->link) =0;
	if(first ==0)
	{
		first=t;
		return;
	}
	node *i=NULL;
	for(i=first ; (i->link)!=NULL ; i=i->link);
	(i->link) = t;
}

void list::delete_F()
{
	if(first ==0)
	{
		cout<<"Empty list\n";
		return;
	}
	node *t=first;
	cout<<"Data : "<<(t->data)<<" Deleted\n";
	first = first->link;
	delete t;
}

void list::delete_R()
{
	if(first ==0)
	{
		cout<<"Empty list\n";
		return;
	}
	if(first->link ==0)
	{
		node *t=first;
		cout<<"Data : "<<(t->data)<<" Deleted\n";
		first = first->link;
		return;
	}
	node *t=first,*p=0;
	for(;t->link !=0; p=t,t=t->link);
	cout<<"Data : "<<(t->data)<<" Deleted\n";
	p->link=0;
	delete t;
}

void list::display()const
{
	if(first ==0)
	{
		cout<<"Empty list\n";
		return;
	}
	cout<<"List Contain : \n";
	for(node *t=first;t!=0;t=t->link)
		cout<<(t->data)<<" ";
	cout<<endl;
}

list::~list()
{
	cout<<"IN destructor\n";
	node *t=first;
	for(;t;t=first)
	{
		first= first->link;
		delete t;
	}
}

list::list(const list &p)
{
	first=0;
	for(node *t=p.first;t!=0;t=t->link)
	{
		insert_R(t->data);
	}
}

/*list::list(const list &p)
{
	for(node *t=p.first;t!=0;t=t->link)
	{
		node *rear;
		node* q=new node;
		q->data = t->data;
		q->link =0;
		if(t==p.first)
			rear = first = q; 
		else
		{		
		rear->link = q;
		rear=q;
		}
	}
}*/
int main()
{
  	list L;
  	/*cout<<"Enter 3 data\n";
  	int d;
  	cin>>d;
  	L.insert_R(d);
  	cin>>d;
  	L.insert_R(d);
  	cin>>d;
  	L.insert_R(d);
  	list t=L;
  	t.display();*/
  	while(1)
  	{
  		int ch=0;
  		cout<<"1:I_F\n2:I_R\n3:D_F\n4:D-R\n5:Display\n6:exit\n";
  		cout<<"7:copy\n";
  		cout<<"Enter choice\n";
  		cin>>ch;
  		switch(ch)
  		{
  			case 1: L.insert_F();	break;
  			case 2: int d;
  				cout<<"Enter data\n";
  				cin>>d;
  				L.insert_R(d);	break;
  			case 3: L.delete_F();	break;
  			case 4: L.delete_R();	break;
  			case 5: L.display();	break;
  			case 7: 
  				{
  					list t=L;
  					cout<<"copied ";
	  				t.display();	
	  				break;
  				}
  			default : exit(0);
  		}
  	}
  	
	return 0;
}
