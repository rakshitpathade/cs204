#include<iostream>
#include<cmath>

using namespace std;

struct Node{
int x;
int y;
struct Node *next;
};
void AddFirst(int a,int b);
void DelFirst();
void Del(int a,int b);
void Search(int d);
bool Search(int x,int y);
int Length();

void function(int a,int x,int y)
{
	switch(a)
	{
		case 1: AddFirst(x,y);
                        break;
		case 2: DelFirst(); 
                        break;
		case 3: Del(x,y); 
                        break;
		case 4: Search(x); 
                        break;        
		case 5: if(Search(x,y)) cout<<"True"<<endl;
		        else cout<<"False"<<endl;
			break;  
		case 6: Length(); 
                        break;
	}
}

int main()
{ 
int t;
cin>>t;

int store[t][3];
	
for(int i=0;i<t;i++)
	{
		int a=0,b=0,c=0;
		cin>>a;
		
if(a==0)
{
	break; 
}

if(!(a==2||a==6||a==4))
{
	cin>>b;
	cin>>c;
}

if(a==4)
{
        cin>>b;
}
	
        store[i][0]=a;
	store[i][1]=b;
	store[i][2]=c;
	}
	
 cout<<endl;
	
for(int j=0;j<t;j++)
	{
		function(store[j][0],store[j][1],store[j][2]);	
	}

}
struct Node *start=NULL;


void AddFirst(int a,int b)
{
	struct Node *temp=new Node;
	temp->x=a;
	temp->y=b;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start; 
		start=temp;
	}
}   
void DelFirst()
{	struct Node *temp;
	temp=start;
	start=temp->next;
	delete temp;
}

void Del(int a,int b)
{	struct Node *temp,*prev;
	temp=start;
	if (temp != NULL && (temp->x==a&&temp->y==b)) 
	{ 
		start = temp->next;    
		delete temp;              
		return; 
	} 

	while (temp != NULL && (temp->x==a&&temp->y==b)) 
	{ 
		prev = temp;               
		temp = temp->next; 
	}
	if (temp == NULL) return;
	prev->next = temp->next; 
	delete temp;
}

void Search(int d)
{	int x,y;
	struct Node *temp;
	temp=start;
	while(temp!=NULL)
	{
		float r=sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
		if(r<=d)
		{  
			cout<<"("<<temp->x<<","<<temp->y<<")";
		}
		temp=temp->next;
	}
	cout<<endl;
}

bool Search(int a,int b)
{	struct Node *temp;
	temp =start;
	while (temp != NULL)  
	{  
		if (temp->x == a && temp->y == b)  
		    return true;  
		temp = temp->next;  
	}  
	return false;
}

int Length()
{	struct Node *temp;
	temp=start;
	int n=1;
	 for(int i=0;temp->next!=NULL;i++)
	 { 
		n=n+1;
		temp=temp->next;
	 }
	cout<<n<<endl;
	return 0;
}























