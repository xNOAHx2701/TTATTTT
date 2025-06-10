#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{  ll D[29]={0};
   string s;
   vector <char> d;
   ll n=0;
   getline(cin,s);
   for(ll i=0;i<s.length();i++)
    {  
        if(D[s[i]-97]==0)
         d.push_back(s[i]);
        D[s[i]-97]++;
    }
   for(ll i=0;i<d.size();i++)
   { ll k=D[d[i]-97];
     n=n+k+(k*(k-1))/2;
   }
   cout<<n;
}