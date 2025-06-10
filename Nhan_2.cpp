#include <bits/stdc++.h>
using namespace std;
long long a;
long long b;
int w = 8;
long long p;
struct KQ{
   bool nho;
   vector <int> array;
};

int mod(int x,int y)
{
  int z=x%y;
  while(z<0) z=z+y;
  return z;
}

vector <int> mang(long long x,int h)
{  vector <int> X;
   for (int i = h - 1; i >= 0; i--) {
        int shift = w * i;
        int j = (x >> shift) & ((1 << w) - 1); // lấy w-bit từ vị trí shift
        X.push_back(j);
    }
     return X;
}

vector <int> dao(vector <int> P)
{  vector<int> Q(P.rbegin(), P.rend());
   return Q;
}


struct KQ cong (vector <int> A, vector <int> B, int F)
{
   bool e=true;
   vector <int> C;
   int T = 1 << w;
   int c0=A[F-1]+B[F-1];
   if(c0<T) {e=false;
             C.push_back(c0);}
   else { c0=mod(c0,T);
      C.push_back(c0);
   }
   for(int i=F-2;i>=0;i--)
   {
    int c=A[i]+B[i]+e;
   if(c<T&&c>=0) {e=false;
   C.push_back(c);}
   else {
      e=true;
      c=mod(c,T);
      C.push_back(c);
   }
   }
   struct KQ kq;
   kq.nho=e;
   kq.array=dao(C);
   return kq;
}
int main()
{
    
}