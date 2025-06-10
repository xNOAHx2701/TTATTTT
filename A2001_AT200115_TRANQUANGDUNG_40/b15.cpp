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

ll random(ll n)
{
  srand((unsigned) time(NULL));
  ll r=(rand()%(n-3))+2;
  return r;
}

bool fermat(ll n,int t)
{   if(n==2) return true;
    if(n==3) return true;
    for(int i=0;i<t;i++)
    {
        ll a= random(n);
        ll r=binhphuongcolap(a,(n-1),n);
        if(r!=1) return false;
    }
    return true;
}

int main()
{
    ll a,b,T;
    T=0;
    cin>>a>>b;
    ll n=b-a+1;
    ll A[n]={0};
    if(a<2) a=2;
    for(ll i=a;i<=b;i++)
    {   
        if(fermat(i,3)==true && A[i-a]==0) {
            ll j=i;
            T=T+i;
            while(j<b)
            {
               A[j-a]=1;
               j+=j;
            }
        }
    }
    cout<<T;
}