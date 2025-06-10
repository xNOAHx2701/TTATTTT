#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> failure(const string &P)
{
   ll n=P.size();
    vector <ll> F(n,0);
    F[0]=0;
    ll i=1,len=0;
    while(i<n)
    {
        if(P[i]==P[len]) {
            len++;
            F[i]=len;
            i++;
        } 
        else if(len>0)
              { 
                len=F[len-1];
              }
              else {    
                F[i]=0;
                i++;
              }

    }   
    F.insert(F.begin(),-1);
    return F;
}

void KMP (string &T, const string &P)
{ ll n=P.size();
  vector <ll> F=failure(P);
  ll i=0;
  ll j=0;
  vector <ll> r={-1};
  while(i<T.length())
  {
    if(T[i+j]==P[j]){
      
       j++; 
       if(j==n)
        { 
          T.erase(i,P.length());
          j=0;
          i++;
        } 
    }
    else {
        i=i+j-F[j];
        if(F[j]==-1) j=0;
        else j=F[j];
    }
  }
}

//void remove(string &s, const string &p)


int main()
{
  string s,p;
  getline(cin,s);
  getline(cin,p);
  KMP(s,p);
  cout<<s;
    return 0;
}