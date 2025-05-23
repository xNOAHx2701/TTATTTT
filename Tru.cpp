#include <bits/stdc++.h>
using namespace std;
long long a;
long long b;
int w=8;
int t=4;
long f;

struct KQ
{
   bool nho;
   vector <int> kq;
};

vector <int> mang(long long x)
{  vector <int> X;
   for(int i=t-1;i>=0;i--)
     {
        int j=x/pow(2,w*i);
        X.push_back(j);
        x=x-j*pow(2,w*i);
     }
     return X;
}
int mod(int x,int y)
{
  int z=x%y;
  while(z<0) z=z+y;
  return z;
}

struct KQ tru(long long a, long long b)
{  struct KQ Tru;
   bool e=true;
   vector <int> A;
   vector <int> B;
   vector <int> C;
   A=mang(a);
   B=mang(b);
   int T=pow(2,w);
   int c0=A[t-1]-B[t-1];
   if(c0<T) {e=false;
             C.push_back(c0);}
   else { c0=mod(c0,T);
      C.push_back(c0);
   }
   for(int i=t-2;i>=0;i--)
   {
    int c=A[i]-B[i]-e;
   if(c<T&&c>=0) {e=false;
   C.push_back(c);}
   else { c=mod(c,T);
      C.push_back(c);
   }
   }
   Tru.kq=C;
   Tru.nho=e;
   return Tru;
}

int main()
{
   cin>>a>>b;
  /*bool e=true;
   vector <int> A;
   vector <int> B;
   vector <int> C;
   A=mang(a);
   B=mang(b);
   int T=pow(2,w);
   int c0=A[t-1]-B[t-1];
   if(c0<T) {e=false;
             C.push_back(c0);}
   else { c0=mod(c0,T);
      C.push_back(c0);
   }
   for(int i=t-2;i>=0;i--)
   {
    int c=A[i]-B[i]-e;
   if(c<T&&c>=0) {e=false;
   C.push_back(c);}
   else { c=mod(c,T);
      C.push_back(c);
   }
   }
   for(int j=0;j<t;j++)
    cout<<C[j]<<" ";
  cout<<e; */
  for(int j=0;j<t;j++)
    cout<<tru(a,b).kq[j]<<" ";
}