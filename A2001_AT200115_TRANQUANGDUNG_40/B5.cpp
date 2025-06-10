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
        d = a;
        x = x2;
        y = y2;
        if(x<0) x=x+B;
        return x;
    }
}

int main()
{ 
   ll a,p;
   p=read();
   a=read();
   ll d=nghichdao(a,p);
   print(d);
   return 0;
}