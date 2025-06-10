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

ll M_R(ll n, ll r, ll a, ll j_max)
{
    ll y = binhphuongcolap(a, r, n);
    if (y != 1 && y != n - 1)
    {
      ll j = 1;
      while (j <= j_max && y != n - 1)
      {
        y = binhphuongcolap(y, 2, n);
        if (y == 1)
          return y;
        j++;
      }
    }
    return y;
}

int main()
{
  ll n,r,a, j_max;
  cin>>n>>r>>a>>j_max;
  ll b=n/r;
  ll s=0;
  while(b>0)
   {
    s++;
    b=(b>>1);
   }
  if(j_max>s-1) cout<<"Too many steps";
  else cout<<M_R(n,r,a,j_max);
return 0;
}
