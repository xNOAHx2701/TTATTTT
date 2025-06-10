#include <bits/stdc++.h>
using namespace std;
typedef __int128 __int128_t;
#define ll long long
/*_int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
*/
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

ll tim(ll x, vector <ll> y)
{
  for(ll i=0;i<y.size();i++)
   {
    if(y[i]==x) return i;
   }
   return -1;
}

int main()
{   vector <ll> baby_step;
    vector <ll> big_step;
    ll n,a,b,x,y;
    cin>>n>>a>>b;
    ll m=ceil(sqrt(n-1));
    for(ll j=0;j<m;j++)
    {
        baby_step.push_back(binhphuongcolap(a,j,n));
    }
    for(ll i=0;i<m;i++)
      { 
        ll a_m=nghichdao(binhphuongcolap(a,m,n),n);
        ll a_m_i=binhphuongcolap(a_m,i,n);
        ll B=mod(a_m_i*b,n);
        big_step.push_back(B);
        if(tim(B,baby_step)!=-1) {
            x=i;
            y=tim(B,baby_step);
            break;}
      }
    cout<<(m*x+y);
    return 0;
}