#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll nghichdao(ll a, ll b)
{   ll d,x,y;
    ll B=b;
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        return x;
    }
    else
    {
        ll x2 = 1;
        ll x1 = 0;
        ll y2 = 0;
        ll y1 = 1;
        while (b > 0)
        {
            ll q = a / b;
            ll r = a - q * b;
            x = x2 - q * x1;
            y = y2 - q * y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }
        //d = a;
        //x = x2;
        //y = y2;
        if(x2<0) x2=x2+B;
        return x2;
    }
}

int main()
{ ll k;
  ll N=1;
  vector <ll> a;
  vector <ll> n;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    ll A,b;
    cin>>A>>b;
    a.push_back(A);
    n.push_back(b);
    N=N*b;
  }
  ll x=0;
 for(int i=0;i<k;i++)
   { ll Ni=N/n[i];
     ll xi=a[i]*Ni*nghichdao(Ni,n[i]);
     x=x+(xi%N);
   }
  cout<<x%N;
}