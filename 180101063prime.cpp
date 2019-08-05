#include <iostream>
#include <math.h>

using namespace std;

void Prime(long a)
{
    double b;
    b=sqrt(a);
    int count=0;
    for(int i=2;i<=b;i++)
    {
        if(a%i==0)
        {
            count++;
            break;
        }
    }
    if(count==1)
    {
        cout<< " Not a Prime" ;
    }
    else
    {
        cout<< " Prime";
    }
}

int main()
{
    int n;
    cin>>n;
    long ar[n];
    for(int i=0;i<n;i++)
    {
    cin>>ar[i];
    }
    cout<<endl;
    for(int j=0;j<n;j++)
    {
        Prime(ar[j]);
        cout<<endl;
    }
    return 0;
}
