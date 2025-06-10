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
/*Cho đường cong Elliptic Ep(a,b) và G là phần
tử sinh với bậc đủ lớn.  Người dùng A chọn khóa riêng kd = nA < n. Khóa công khai
của người dùng A sẽ được tính bằng PA = nA x G. Ta thu được khóa công khai ke =
(Ep(a,b), G, PA )
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
    if (a < 0)
        u += p;
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
    if (x1 < 0)
        x1 += p;
    return x1;
}
pp cong(pp P, pp Q, ll p, ll a)
{
    ll x, y;
    ll omega;
    if (P.first == Q.first && Q.second == (P.second * -1))
    {
        return {0, 0};
    }
    else
    {
        if (P.first == Q.first && Q.second == P.second)
        {
            omega = (3 * pow(P.first, 2) + a) * nghichdao((2 * P.second), p);
        }
        else
        {
            omega = (Q.second - P.second) * nghichdao((Q.first - P.first), p);
        }

        omega = mod(omega, p);
        x = pow(omega, 2) - P.first - Q.first;
        y = omega * (P.first - x) - P.second;
        x=mod(x,p);
        y=mod(y,p);
        return {x, y};
    }
}

int main()
{
    ll p, a, b, n;
    pp G;
    p = read();
    a = read();
    b = read();
    G.first = read();
    G.second = read();
    n=read();
    bool even=true;
    if(n%2==1) even=false;
    pp A=G;
    while (n>1)
    {
       G=cong(G,G,p,a);
       n=n/2;
    }
    if(even==false) G=cong(G,A,p,a);
    print(G.first);
    cout<<" ";
    print(G.second);
    return 0;
}