#include <bits/stdc++.h>
using namespace std;
typedef __int128 __int128_t;
#define ll __int128

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

ll mont(ll a, ll b,ll p, ll R)
{
    ll t=a*b;
    ll p1=nghichdao(p*(-1),R);
    ll m=(t*p1)%R;
    ll u=(t+m*p)/R;
    if(u>=p) return u-p;
    else return u;

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

ll luythua(ll x, ll e, ll p, ll R)
{
   ll p1=nghichdao(p*(-1),R);
   ll x_m=x*R%p;
   ll A=R%p;
   vector <int> E=bieudiennhiphan(e);
   for(int i=E.size()-1;i>=0;i--)
    {
        A=mont(A,A,p,R);
        if(E[i]==1) A=mont(A,x_m,p,R);
    }
  return mont(A,1,p,R);
}

int main()
{   ll a=3;
    ll b=5;
    ll p=7;
    ll R=8;
    print(luythua(a,b,p,R));
    return 0;
}