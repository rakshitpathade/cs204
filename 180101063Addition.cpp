#include<iostream>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;

void reverseStr(string& str) 
{ 
    int n = str.length(); 
   
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

string add( string a, string b)
{

string c= " ";
int carry = 0;

int l1= a.length();
int l2= b.length();


if(l1>l2)
swap(a,b);

reverseStr(a);
reverseStr(b);

 
    for (int i=0; i<l1; i++) 
    { 
        
        int sum = ((a[i]-'0')+(b[i]-'0')+carry); 
        c.push_back(sum%10 + '0'); 
         carry = sum/10; 
    } 
  
   
    for (int i=l1; i<l2; i++) 
    { 
        int sum = ((b[i]-'0')+carry); 
        c.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
   
    if (carry) 
        c.push_back(carry+'0'); 
  
reverseStr(c); 
  
    return c; 
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
for(int j=0; j<t; j++)
{
 string d=add(a[j][0],a[j][1]);
cout<<d;
} return 0; 
}



