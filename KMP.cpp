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

ll KMP (const string &T, const string &P)
{ ll n=P.size();
  vector <ll> F=failure(P);
  ll i=0;
  ll j=0;
  while(i<T.length())
  {
    if(T[i+j]==P[j]){
        if(j==n-1) return i;
        ++j;
    }
    else {
        i=i+j-F[j];
        if(F[j]==-1) j=0;
        else j=F[j];
    }
  }
  return -1;
}

int main()
{   string T;
    string P;
    cin>>P;
    vector <ll> F=failure(P);
    for(auto i:F)
     cout<<i<<" ";
    return 0;
}