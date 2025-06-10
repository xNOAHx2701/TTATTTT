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
     return b;//b=a^k mond n
  }
}

int main()
{
  ll p,g,k,y,m;
  cin>>p>>g>>k>>y>>m;
  ll a=binhphuongcolap(g,k,p);
  ll y1=binhphuongcolap(y,k,p);
  ll b=(m*y1)%p;
  cout<<a<<endl;
  cout<<b;
  return 0;
}