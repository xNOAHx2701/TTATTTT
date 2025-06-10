#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll max(ll a, ll b)
{
    if(a<b) return b;
    return a;
}

int main()
{   bool dd[26]={false};
    dd['e'-97]=true;  dd['o'-97]=true;  dd['a'-97]=true;  dd['i'-97]=true;  dd['u'-97]=true;
    string s;
    getline(cin,s);
    ll i=0,dn=0,dp=0,na=-1,pa=-1;
    ll arr[s.size()+1]={0};
    while(i<s.length())
    {   
        if(dd[s[i]-97]==false||s[i]=='?')
         dp++;
        else dp=0;
        if(dd[s[i]-97]==true||s[i]=='?')
          dn++;
        else dn=0;
        na=max(na,dn);
        pa=max(pa,dp);
        i++;
    }
    if(dn>5||dp>3) cout<<"BAD";
        else cout<<"GOOD";
    return 0;
}