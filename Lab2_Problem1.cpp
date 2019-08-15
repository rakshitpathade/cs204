#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x;
    int y;
    Node *next;
};

struct Node* head = NULL;

void AddFirst(int x , int y);
void DelFirst();
void Del( int x,int y);
void Search(int d);
string Search(int x,int y);
int Length();

int main()
{
    long long int no;
    cin>>no;

    while(no--)
    {
        int select;

        cin>>select;

        if(select==1)
        {
            int x,y;
            cin>>x>>y;
            AddFirst(x,y);
        }
        else if(select==2)
        {
            DelFirst();
        }
        else if(select==3)
        {
            int x,y;
            cin>>x>>y;
            Del(x,y);
        }
        else if(select==4)
        {
            int d;
            cin>>d;
            Search(d);
            cout<<endl;

        }
        else if(select==5)
        {
            int x,y;
            cin>>x>>y;
            cout<<Search(x,y)<<endl;
        }
        else if(select==6)
        {
            cout<<Length()<<endl;
        }
    }
}


void AddFirst(int x , int y)
{
    Node* temp = new Node;

    temp->x  = x;
    temp->y  = y;

    temp->next = head;

    head = temp;
}


void DelFirst()
{
    if (head == NULL)
        {
            cout<<"-1";
            return ;
        }

    Node* temp = head;
    head = head->next;

    free(temp);

}


void Del( int x,int y)
{

   if (head == NULL)
      {
        cout<<"-1";
        return ;
      }


   Node* temp = head;

   Node* prev = NULL;

    if ((head->x)==x&&(head->y)==y)
    {
        head = temp->next;
        free(temp);
        return;
    }


    for (int i=0; temp!=NULL; i++)
         {
             if(temp->x==x&&temp->y==y)
             {
                 break;
             }
             prev = temp;
             temp = temp->next;
         }

    if (temp == NULL )
      {
        cout<<"-1";
        return;
    }

    struct Node *next = temp->next;

    free(temp);

    prev->next = next;
}


void Search(int d)
{
    struct Node* temp = head;
    int a,b;
    int c= 0;
    while (temp!= NULL) {
        a = temp->x;
        b = temp->y;
        if(a*a+b*b<=d*d)
        {
            c++;
        }
        temp=temp->next;
    }
    if(c==0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<c;
    }    
}


string Search(int x,int y)
{
    struct Node* temp = head;

    while (temp!= NULL) {

        if((temp->x)==x&&(temp->y)==y)
        {
            return "True";
        }
        temp=temp->next;
    }
    return "False";
}


int Length()
{
    struct Node* temp = head;
    int l=0;
    while (temp!= NULL) {
        l++;
        temp=temp->next;
    }
    return l;
}





  
