#include <bits/stdc++.h>
using namespace std;
long long a;
long long b;
int w=8;
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
   for(int i=h-1;i>=0;i--)
     {
        int j=x/pow(2,w*i);
        X.push_back(j);
        x=x-j*pow(2,w*i);
     }
     return X;
}

vector <int> dao(vector <int> P)
{  vector <int> Q;
   for(int i=P.size()-1;i>=0;i--)
     Q.push_back(P[i]);
   return Q;
}


struct KQ cong (vector <int> A, vector <int> B, int F)
{
   bool e=true;
   vector <int> C;
   int T=pow(2,w);
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

struct KQ tru ( vector <int> A, vector <int> B, int F)
{
   bool e;
   vector <int> C;
   int T=pow(2,w);
   int c0=A[F-1]-B[F-1];
   if(c0<T&&c0>=0) {e=false;
                    C.push_back(c0);}
   else {  e=true;
           c0=mod(c0,T);
           C.push_back(c0);
        }
   for(int i=F-2;i>=0;i--)
   {
    int c=A[i]-B[i]-e;
    if(c<T&&c>=0) {e=false;
                   C.push_back(c);}
    else { e=true;
         c=mod(c,T);
    C.push_back(c);
   }
   }
   struct KQ kq;
   kq.nho=e;
   kq.array=dao(C);
   return kq;
}

bool sosanh(vector <int> A, vector <int> B) 
{
   for(int i=0;i<A.size();i++)
     if(A[i]>B[i]) return true;
   return false;
}



int main()
{  cin >> p;
   int t=round(log2(p)/w);
   cin>>a; cin>>b;
   cout<<"cong a va b chon 1: \n";
   cout<<"tru a va b chon 2: \n";
   int luachon;
   cin>>luachon;
   struct KQ ketqua;
   switch (luachon)
   {
      case 1: ketqua=cong(mang(a,t),mang(b,t),t); 
             if(ketqua.nho==1) ketqua=tru(ketqua.array,mang(p,t),t);  
             else if(sosanh(ketqua.array,mang(p,t))==true) ketqua=tru(ketqua.array,mang(p,t),t);
       break;
      case 2: ketqua=tru(mang(a,t),mang(b,t),t);
              if(ketqua.nho==1) ketqua=cong(ketqua.array,mang(p,t),t); 
       break;
   }
  
  for(int j=0;j<t;j++)
    cout<<ketqua.array[j]<<" ";
   cout<<"\n"<<ketqua.nho;
}