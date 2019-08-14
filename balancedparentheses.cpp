#include<bits/stdc++.h>

using namespace std;

bool check(string c)
{
stack<char> s;

char a;

for(int i=0;i<c.length();i++)
{ 
     if(c[i]=='('||c[i]=='['||c[i]=='{'||c[i]=='<')
{
s.push(c[i]);

continue;}

if(c[i]=='|'&&s.empty())
{
s.push(c[i]);

continue;}

if(c[i]=='|'&& !s.empty())
{
a=s.top();
if(a=='|')
{s.pop();}
if(a!='|')
{s.push('|');}}

if((c[i]=='}'||c[i]==')'||c[i]==']'||c[i]=='>')&& s.empty())
{return false;
break;}

if(c[i]=='}')
{a=s.top();
if(a=='{')
s.pop();
if(a!='{')
{return false;
break;}}

if(c[i]==')')
{a=s.top();
if(a=='(')
s.pop();
if(a!='(')
{return false;
break;}}

if(c[i]=='>')
{a=s.top();
if(a=='<')
s.pop();
if(a!='<')
{return false;
break;}}

if(c[i]==']')
{a=s.top();
if(a=='[')
s.pop();
if(a!='[')
{return false;
break;}}

}
return(s.empty());}


int main()
{int n,i,j;
cin>>n;
for(i=0;i<n;i++)
{string s;
cin>>s;
if (check(s)) 
        cout << "YES"<<endl; 
    else
        cout << "NO"<<endl; }}
