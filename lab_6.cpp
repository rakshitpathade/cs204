#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N; //Enter no. of users

	int Q;
	cin>>Q; //Enter no. of queries

	int c[N]={ }; //b->id  c->amount

//std::vector <string> v;

int a;
int count=0;

int b1, c1, j;

while(Q--)
{
cin>>a; 

switch (a)
{
case 1: 

cin>>b1>>c1;
c[b1-1]+=c1;
count++;
break;

case 2: 
int k=0;

if(count==0)
{
cout<<"No data available";
//v.push_back("No data available");
}

else{
int max=c[0];
for (int i=0; i<N; i++)
{
if(c[i]>max)
{max=c[i];
j=i;
}

}
//string d=to_string(j);
//v.push_back(d);
cout<<j+1<<endl;
}
}
}

/*v.shrink_to_fit();
for(auto it=v.begin(); it!=v.end(); ++it)
{
cout<<*it<<endl;
}*/
return 0;
}


