#include <bits/stdc++.h>
using namespace std;
#define ll long long

map <char,ll> dem(const string &p)
{  map <char,ll> F;
   for(ll i=0;i<p.length();i++)
   {if(!F.count(p[i]))
       F[p[i]]=1;
    else F.at(p[i])++;
   }
   return F;
}

int main()
{   
    string s,p;
    getline(cin,s);
    getline(cin,p);
    ll n=p.length();
    map <char,ll> P=dem(p);
    map <char,ll> S=dem(s.substr(0,n));
    ll i=0;
    while(i<=s.length()-n)
    {   bool kt=true;
        for(auto k:P)
         if(P[k.first]!=S[k.first]) {kt=false; break;}         
         if(kt==true) cout<<i<<" ";
        S.at(s[i])--;
        if(!S.count(s[i+n])) S[s[i+n]]=1;
        else S.at(s[i+n])++;
        i++;
    }
    return 0;
}