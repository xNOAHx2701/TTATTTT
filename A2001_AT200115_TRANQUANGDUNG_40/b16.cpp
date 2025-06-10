#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <int> bieudiennhiphan (ll k)
{
  vector <int> K;
  K.push_back((k&1));
    while(k!=0){
        K.push_back(((k>>1)&1));
        k=(k>>1);
    }
  K.pop_back();
  return K;
}

ll binhphuongcolap(ll a,ll K, ll n)
{
  ll b=1; ll A;
  vector <int> k=bieudiennhiphan(K);
  if(K==0) return b;
  else {
     A=a;
     if(k[0]==1) b=a;
     for(int i=1;i<k.size();i++)
      {
        A=(A*A)%n;
        if(k[i]==1) b=(A*b)%n;
      }
     return b;
  }
}

bool fermat(ll n,int t)
{ 
    ll r=binhphuongcolap(t,(n-1),n);
    if(r!=1) return false;
    return true;
}

int main()
{
    ll n,T,t;
    bool kt=false;
    int d;
    cin>>n;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>t;
        if(fermat(n,t)==false) {kt=false;
          d=i+1;
        }
    }
    if(kt==false) cout<<d;
    else cout<<-1;
}