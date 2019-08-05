#include <bits/stdc++.h>

using namespace std;

string sum(string str1, string str2)
{
    int n1=str1.length();
    int n2=str2.length();
    int flag=n1;
    int s=0;
    int carry=0;
    if(n1>n2)
    {
        for(int j1=0;j1<n1-n2;j1++)
        {
            str2='0'+str2;
        }
    }

    if(n2>n1)
    {
        flag=n2;
        for(int k1=0;k1<n2-n1;k1++)
        {
            str1='0'+str1;
        }
    }
    string sum="";
    string t;
    for(int l=0;l<flag;l++)
    {
        if(l<flag-1)
        {
        s=(str1[flag-l-1]-'0')+(str2[flag-l-1]-'0')+carry;
        carry=s/10;
        t=(s%10)+'0';
        sum=t+sum;
        }
        else if (l==flag-1)
        {
            s=(str1[flag-l-1]-'0')+(str2[flag-l-1]-'0')+carry;
            carry=(s/10);
            t=(s%10)+'0';
            sum=t+sum;
            t="";
            t=carry+'0';
            sum=t+sum;
        }
    }
    return sum;
}

void product(string str1,string str2)
{
    int n1=str1.length();
    int n2=str2.length();

    string ar[n2];
    string t1="";
    string t="";
    int carry=0;
    string s="";
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n1;j++)
        {
            if (j<n1-1)
            {
            int a = (str2[n2-i-1]-'0')*(str1[n1-j-1]-'0')+carry;
            carry=a/10;
            t1=((a%10)+'0');
            t=t1+t;
            }
            else if(j==n1-1)
            {
            int a = (str2[n2-i-1]-'0')*(str1[n1-j-1]-'0')+carry;
            carry=a/10;
            t1=((a%10)+'0');
            t=t1+t;
            t1=carry+'0';
            t=t1+t;
            }
        }
        ar[i]=t+s;
        s=s+'0';
        t="";
    }
    for(int l=0;l<n2-1;l++)
    {
        ar[l+1]=sum(ar[l],ar[l+1]);
    }
    cout<<ar[n2-1];
}
int main()
{
    int n;
    cin>>n;
    string ar[n][2];
    for(int i=0;i<n;i++)
    {
    cin>>ar[i][0];
    cin>>ar[i][1];
    }
    cout<<endl;
    for(int j=0;j<n;j++)
    {
        product(ar[j][0],ar[j][1]);
        cout<<endl;
    }
}
