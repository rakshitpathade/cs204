//Array Implementation of Queue


#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
int front, rear, cursize;
unsigned storage;
int* array;
};

Queue* newque(unsigned storage)
{
    Queue* que = new Queue();
    que->storage=storage;
    que->front=que->cursize=0;
    que->rear=storage-1;
    que->array=new int[(que->storage * sizeof(int))];
    return que;
}

int isFull(Queue* que)
{
    return(que->cursize==que->storage);

}

int isEmpty(Queue* que)
{
    return(que->cursize==0);
}

void Enqueue( Queue* que, int ele)
{   if(isFull(que))
    return;
    que->rear= (que->rear + 1)%(que->storage);
    que->array[que->rear]=ele;
    que->cursize=que->cursize+1;
    cout<<ele<<"Enqueued;"<<endl;
}

int Dequeue( Queue* que)
{
   if(isEmpty(que))
   return INT_MIN;
   int ele=(que->array[que->front]);
   que->front=(que->front+1)%que->storage;
   que->cursize=que->cursize - 1;
   return ele;  
}

int front(Queue* que)
{
    if(isEmpty(que))
    return INT_MIN;
    return que->array[que->front];
}

int rear(Queue* que)
{
    if(isEmpty(que))
    return INT_MIN;
    return que->array[que->rear];
}

int main()
{
    Queue* que= newque(1000);
    Enqueue(que, 10);
    Enqueue(que, 20);
    Enqueue(que, 30);
    Enqueue(que, 40);

     cout<<Dequeue(que)<<" dequeued from queue\n"<<endl;  
  
    cout << "Front item is " << front(que) << endl;  
    cout << "Rear item is " << rear(que) << endl;
  
    return 0;  

}
