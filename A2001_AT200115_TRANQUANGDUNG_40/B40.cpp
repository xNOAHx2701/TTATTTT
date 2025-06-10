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

bool KMP (const string &T, const string &P)
{ ll n=P.size();
  vector <ll> F=failure(P);
  ll i=0;
  ll j=0;
  while(i<T.length())
  {
    if(T[i+j]==P[j]){
        j++;
        if(j==n)
          {
            return true;
          }
           
    }
    else {
        i=i+j-F[j];
        if(F[j]==-1) j=0;
        else j=F[j];
    }
  }
  return false;
}

int main()
{
    ll n;
    vector <string> w;
    cin>>n;
    cin.ignore();
    for(ll i=0;i<n;i++)
     {  string s;
        getline(cin,s);
        w.push_back(s);
     }
    bool nu=false;
    for(ll i=0;i<n;i++)
      {
        for(ll j=0;j<n;j++)
         if(i!=j) {
            if(KMP(w[j],w[i]))
             { 
                nu=true;
                cout<<w[i]<<" ";    
             }  
         }
      }
    if(!nu) cout<<"None";
    return 0;
}