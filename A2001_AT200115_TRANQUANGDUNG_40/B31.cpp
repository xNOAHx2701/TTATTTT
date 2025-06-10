#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> failure(const string &P)
{
 ll n=P.size();
    vector <ll> F(n,0);
    F[0]=0;
    ll i=1,len=0;
    while(i<n)
    {
        if(P[i]==P[len]) {
            len++;
            F[i]=len;
            i++;
        } 
        else if(len>0)
              { 
                len=F[len-1];
              }
              else {    
                F[i]=0;
                i++;
              }

    }   
    F.insert(F.begin(),-1);
    return F;
}
int main()
{
    string s;
    getline(cin,s);
    ll n=s.length();
    vector <ll> F=failure(s);
    ll len=n-F[n];
    if(n%len==0&&len!=n)
     cout<<"YES";
    else cout<<"NO";
    return 0;
}