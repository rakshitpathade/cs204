#include<bits/stdc++.h>

using namespace std;

void Sub(string str1, string str2)
{
    int flag=str1.length();
    int n1=flag;
    int n2=str2.length();
    int diff=0;
    int carry=1;
    string d="";
    string t="";
    for(int i=0;i<n1-n2;i++)
    {
        str2='0'+str2;
    }
    for(int l=0;l<flag;l++)
    {
        if((str1[flag-l-1]-'0')>(str2[flag-l-1]-'0'))
        {
            diff=(str1[flag-l-1]-'0')-(str2[flag-l-1]-'0');
            t=diff+'0';
            d=t+d;
        }
        if((str1[flag-l-1]-'0')<(str2[flag-l-1]-'0'))
        {
            str1[flag-l-2]=((str1[flag-l-2]-'0')-1)+'0';
            diff=(str1[flag-l-1]-'0')-(str2[flag-l-1]-'0')+10;
            t=diff+'0';
            d=t+d;
        }
    }
    cout<<d;
}

int main()
{
     int t;
cout<<"Enter the no. of test cases:";
cin>>t;
string a[t][2];    
for(int i=0; i<t;i++)
{
cin>>a[i][0];
cin>>a[i][1];
}
cout<<endl;
for(int j=0; j<t; j++)
{
 Sub(a[j][0],a[j][1]);
cout<<endl;
}

}
