#include <bits/stdc++.h>
using namespace std;
#define ll long long
int L[128];
// ll Boyer_Moore (string T, string P)

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

ll B_M(string t, string p, int l[])
{
  ll m=p.length();
  ll j=m-1;
  ll i=j;
  while(j>0)
   {
    if(t[i]==p[j]) {
        i=i-1;
        j=j-1;
    }
    else
    {
       i=i+m-min(j,1+l[t[i]-32]);
        if(i>t.length()) return -1;
       j=m-1;
    }
   }
   return i;
}

int main()
{   fill_n(L,128,-1);
    string T;
    string P;
    getline(cin,T);
    P=read();
    cout<<B_M(T,P,L);
}