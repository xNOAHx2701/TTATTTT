#include <bits/stdc++.h>
using namespace std;
typedef __int128 __int128_t;
#define ll __int128
ll a;
ll b;
int w = 8;
struct KQ
{
    ll d;
    ll x;
    ll y;
};

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

struct KQ euclicde(ll a, ll b)
{
    struct KQ kq;
    if (b == 0)
    {
        kq.d = a;
        kq.x = 1;
        kq.y = 0;
        return kq;
    }
    else
    {
        long x2 = 1;
        long x1 = 0;
        long y2 = 0;
        long y1 = 1;
        while (b > 0)
        {
            long q = a / b;
            long r = a - q * b;
            kq.x = x2 - q * x1;
            kq.y = y2 - q * y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = kq.x;
            y2 = y1;
            y1 = kq.y;
        }
        if (x2 < 0)
            x2 = x2 + b;
        if (y2 < 0)
            y2 = y2 + a;
        kq.d = a;
        kq.x = x2;
        kq.y = y2;
        return kq;
    }
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
int main()
{
    ll x, y, d;
    a = read();
    b = read();
    struct KQ ketqua = euclicde(a, b);
    // x la nghich dao a mod b y la nghich dao b mod a
    print(ketqua.x);
    print(nghichdao(a, b));
}