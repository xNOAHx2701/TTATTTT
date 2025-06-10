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

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
   ll p,q,m,d;
   p=read(); q=read(); m=read(); d=read();
   int t = ceil(log2(p) / w)*2;
   ll n=mang_sangso(nhan(mang(p,t),mang(q,t),t));
   ll s=binhphuongcolap(m,d,n);
   print(s);
   return 0;
}