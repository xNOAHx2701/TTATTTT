#include <bits/stdc++.h>
using namespace std;
typedef __int128 __int128_t;
#define ll __int128
#define pp pair<ll, ll>
__int128 read()
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

ll nghichdao(ll a, ll p)
{
    ll u = a;
    if(a<0) u+=p;
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

ll mod(ll x, ll y)
{
    ll z = x % y;
    while (z < 0)
        z = z + y;
    return z;
}

int main()
{
    ll p, a, x, y;
    pp P;
    pp Q;
    ll omega;
    p = read();
    a = read();
    P.first = read();
    P.second = read();
    Q.first = read();
    Q.second = read();
    if (P.first == Q.first && Q.second == (P.second * -1))
    {
        cout << 0 << " " << 0;
    }
    else
    {
        if (P.first == Q.first && Q.second == P.second)
        {
            omega = (3 * pow(P.first,2) + a) * nghichdao((2 * P.second),p);
        }
        else
        {
            omega = (Q.second - P.second) * nghichdao((Q.first - P.first),p);
        }

        omega = mod(omega, p);
        x = pow(omega,2) - P.first - Q.first;
        y = omega * (P.first - x) - P.second;
    }
    print(mod(x,p));
    cout<<" ";
    print(mod(y,p));
    return 0;
}