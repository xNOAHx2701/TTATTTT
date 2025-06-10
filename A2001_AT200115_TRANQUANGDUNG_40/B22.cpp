#include <bits/stdc++.h>
using namespace std;
#define ll long long
int L[100];
string read()
{
    string s = "";
    char ch = getchar();
    ll i = 0;
    while(ch<' ' && ch>'~')
        ch=getchar();
    while (ch>=' '&&ch<='~')
    {    
        ll j = ch - 32;
        L[j] = i;
        s = s + ch;
        ch = getchar();
        i++;
    }
    return s;
}

ll min(ll a, ll b)
{
   if(a<b) return a;
   else return b;
}

void B_M(const string &t,const string &p, int l[])
{
  ll m=p.length();
  ll j=m-1;
  ll i=j;
  bool k=false;
  while(i<t.length())
  {
    if(t[i]==p[j]) 
    {  
        if(j==0) 
        {
            k=true;
            cout<<i+1<<" ";
            i=i+m; 
            j=m-1;
        }
        i=i-1;
        j=j-1;
        
    }
    else
    {
       i=i+m-min(j,1+l[t[i]-32]);
       j=m-1;
    }
  }
  if(k==false) cout<<-1;
}

int main()
{ fill_n(L,100,-1);
  string t;
  string p;
  getline(cin,t);
  p=read();
  B_M(t,p,L);
  return 0;
}