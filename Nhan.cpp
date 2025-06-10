#include <bits/stdc++.h>
using namespace std;
long long a;
long long b;
int w = 8;
long long p;
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

vector<int> mang(long long x, int h)
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

long long mang_sangso (vector <int> A)
{
  long long x;
  for(int i=A.size()-1;i>=0;i--)
    x=(x<<w)+A[i];
  return x;
}

vector<int> nhan(vector<int> A, vector<int> B, int F)
{
  long long U;
  vector<int> C;
  for (int i = 0; i < 2 * F; i++)
    C.push_back(0);
  for (int i = 0; i < F; i++)
  {
    U = 0;
    for (int j = 0; j < F; j++)
    {
      long uv = C[i + j] + A[i] * B[j] + U;
      U = (uv >> w) & ((1 << w) - 1);
      long V = uv & ((1 << w) - 1);
      C[i + j] = V;
    }
    C[i + F] = U;
  }
  return C;
}
int main()
{
  cin >> p;
  int t = ceil(log2(p) / w);
  cin >> a;
  cin >> b;
  vector<int> kq = nhan(mang(a, t), mang(b, t), t);
  for (int i = 2 * t - 1; i >= 0; i--)
    cout << kq[i] << " ";
}