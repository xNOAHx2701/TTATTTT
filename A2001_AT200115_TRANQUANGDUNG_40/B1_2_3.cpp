#include <bits/stdc++.h>
using namespace std;
typedef __int128 __int128_t;
#define ll __int128
int w=8;
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

int mod(int x, int y)
{
  int z = x % y;
  while (z < 0)
    z = z + y;
  return z;
}

vector<int> dao(vector<int> P)
{
  vector<int> Q(P.rbegin(), P.rend());
  return Q;
}

vector<int> mang(ll x, int h)
{
  vector<int> X;
  for (int i = h - 1; i >= 0; i--)
  {
    int shift = w * i;
    int j = (x >> shift) & ((1 << w) - 1); // lấy w-bit từ vị trí shift
    X.push_back(j);
  }
  return dao(X);
}

ll mang_sangso (vector <int> A)
{
  ll x;
  for(int i=A.size()-1;i>=0;i--)
    x=(x<<w)+A[i];
  return x;
}

vector<int> nhan(vector<int> A, vector<int> B, int F)
{
  ll U;
  vector<int> C;
  for (int i = 0; i < 2 * F; i++)
    C.push_back(0);
  for (int i = 0; i < F; i++)
  {
    U = 0;
    for (int j = 0; j < F; j++)
    {
      ll uv = C[i + j] + A[i] * B[j] + U;
      U = (uv >> w) & ((1 << w) - 1);
      ll V = uv & ((1 << w) - 1);
      C[i + j] = V;
    }
    C[i + F] = U;
  }
  return C;
}

ll nghichdao(ll a, ll b)
{   ll d,x,y;
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
        return x;
    }
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

void b1(ll p, ll q, ll e)
{ 
    ll n=p*q;
    ll fein=(p-1)*(q-1);
    ll d=nghichdao(e,fein);
    if(d<0) d=d+fein;
    print(n);
    cout<<endl;
    print(d);
}

void b2(ll p, ll q, ll e, ll m)
{
   ll n=p*q;
   ll B2=binhphuongcolap(m,e,n);
   print(B2);
}
void b3(ll p, ll q, ll m)
{
   ll n=p*q;
   ll B3=binhphuongcolap(m,2,n);
   //cout<<B3;
   print(B3);
}
int main()
{   ll p,q,e,m;
    cout<<"chọn bài 1,2,3: \n";
    int lc;
    cin>>lc;
    switch(lc)
    {
      case 1:
       p=read();
       q=read();
       e=read();
       b1(p,q,e);
       break;
      case 2:
       p=read();
       q=read();
       e=read();
       m=read();
       b2(p,q,e,m);
       break;
      case 3:
       p=read();
       q=read();
       m=read();
       b3(p,q,m);
        break;
      default: cout<<"moi nhap lai";
    }
    return 0;
}