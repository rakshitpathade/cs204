#include<bits/stdc++.h>

using namespace std;

long long precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else if(c=='$')
    return 4;
    return -1; 
} 

long long check(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    if(c=='^'||c=='$')
    return 2;
    return 0;
}

long long mapop(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
        case '$': return -2;
    }
    return 0;
}

vector<long long > postfix(string s)
{
    vector<long long > S;
    stack<long long> O;
    long long f=0,a;
    O.push('N');
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                S[S.size()-1]=S[S.size()-1]*10+s[i]-'0';
            }
            else 
            {
                S.push_back(s[i]-'0');
                f=1;
            }
        }

        else 
        {
            f=0;
            if(s[i]=='(')
                O.push('(');
            else if(s[i]==')')
            {
                while(O.top()!='N'&&O.top()!='(')
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                if(O.top()=='(')
                    O.pop();   
            }
            else if(check(s[i])==1)
            {
                while(O.top()!='N'&&O.top()!='('&&precedence(s[i])<=precedence(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                O.push(s[i]);
            }
            else if(check(s[i])==2)
            {
                while(O.top()!='N'&&O.top()!='('&&precedence(s[i])<precedence(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push_back(mapop(c));
        }
    return S;
}

struct node
{
    long long i;
    node * left,* right,* parent;
};

node * newNode(long long v)
{
    node * temp=new node;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}

node * etree(vector<long long > v)
{
    node *t,*t1,*t2;
    stack<node *> st;
    for(long long i=0;i<v.size();i++)
    {
        if(v[i]>=0)
        {
            t=newNode(v[i]);
            st.push(t);
        }
        else
        {
            t=newNode(v[i]);
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            if(1)
            {t->right=t1;
            t->left=t2;}
            st.push(t);
        }
    }
    return t;
}


void show(vector<long long > s)
{
    for(long long i=0;i<s.size();i++)
    {
        cout<<s[i]<<' ';
    }
}

void printInorder(struct node* n) 
{ 
    if (n == NULL) 
        return; 
    printInorder(n->left); 
    cout << n->i << " "; 
    printInorder(n->right); 
} 

long long eval(node* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return root->i;  
    long long l_val = eval(root->left);  
    long long r_val = eval(root->right);  
    if (root->i==-1)  
        return l_val+r_val;  
    if (root->i==-2)  
        return l_val-r_val;  
    if (root->i==-3)  
        return l_val*r_val;  
    if(root->i==-4)
        return l_val/r_val;
    return pow(l_val,r_val);  
} 

int idno(char c)
{
    if(isupper(c))
        return c-'A';
    return c-'a';
}

long long value(string s)
{
    vector <long long > S;
    S=postfix(s);
    node *p=etree(S);
    return eval(p);
}

long long find(vector<string> *M,string s)
{
    for(int i=0;i<M->size();i++)
    {
        if(!s.compare((*M)[i]))
            return i;
    }
    return M->size();
}

void process(string s,vector<string> *M, vector<long long> *N)
{
    string s1="";
    vector<long long> dl;
    long long u=1;
    dl.push_back(-1);
    for(long long i=0;i<s.length();i++)
    {
        if(u&&s[i]=='-')
        {
            s[i]='$';
            s.insert(i,"0");
        }
        if(check(s[i])||s[i]=='('||s[i]=='=')
            u=1;
        else u=0;
        if(check(s[i])||s[i]=='('||s[i]==')'||s[i]=='=')
        {
            dl.push_back(i);
        }
    }
    dl.push_back(s.length());
    string t,v="";
    if(s[dl[1]]=='=')
    {
        v=s.substr(dl[0]+1,dl[1]-dl[0]-1);
        dl[0]=dl[1];
        dl.erase(dl.begin()+1);
    }
    for(int i=0;i<dl.size()-1;i++) 
    {
        t=s.substr(dl[i]+1,dl[i+1]-dl[i]-1);
        if(!t.size())
            {
                s1+=s[dl[i+1]];
                continue;
            }
        if(isdigit(t[0]))
        {
            s1+=t;
        }
        else
        {
            long long i=find(M,t);
            if(i==M->size())
            {
                cout<<"CANT BE EVALUATED"<<endl;
                return;
            }
            else
            {
                string p=to_string((*N)[i]);
                if(p[0]=='-')
                    p="0$"+p.substr(1);
                s1+=p;
            }
        }
        if(i+1<dl.size())
        {
            s1+=s[dl[i+1]];
        }
    }
    
    if(v.length())
    {
        long long i=find(M,v);
        if(i==M->size())
        {
            M->push_back(v);
            N->push_back(value(s1));
        }
        else (*N)[i]=value(s1);

    }
    else
    {
        cout<<value(s1)<<endl;
    }
}

int main()
{   
    long long q;
    cin>>q;
    while(q--)
    {
        long long T;
        cin>>T;
        vector<string> M;
        vector<long long> N;
        while(T--)
        {
            long long u=1;
            string s;
            cin>>s;
            process(s,&M,&N);
        }
    }
	return 0;
}
