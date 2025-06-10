#include <bits/stdc++.h>
using namespace std;
typedef __int128 __int128_t;
#define ll __int128
#define pp pair<ll, ll>
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

ll mod(ll x, ll y)
{
    ll z = x % y;
    while (z < 0)
        z = z + y;
    return z;
}

ll nghichdao(ll a, ll p)
{
    ll u = a;
    ll v = p;
    ll x1 = 1;
    ll x2 = 0;
    while (u != 1)
    {
       ll q = v / u;
       ll r = v - q * u;
       ll x = x2 - q * x1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    if(x1<0) x1+=p;
    return x1;
}

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

// chu ky so sig_k(x)
int main()
{
     ll p,alpha,a,k,x;
     p=read();
     alpha=read();
     a=read();
     k=read();
     x=read();
     ll gamma=binhphuongcolap(alpha,k,p);
     ll sig=nghichdao(k,p-1);
     ll ma=mod(x-a*gamma,p-1);
     ll sigma=mod(sig*ma,p-1);
     print(gamma); cout<<" "; print(sigma);
}