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

void KMP (const string &T, const string &P,vector <bool> &B)
{ ll n=P.size();
  vector <ll> F=failure(P);
  ll i=0;
  ll j=0;
  while(i<T.length())
  {
    if(T[i+j]==P[j]){
        j++;
        if(j==n)
        {   for(ll b=i;b<i+n;b++)
             {  
                B[b]=true;
             }
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

int main()
{   string str;
    getline(cin,str);
    ll n;
    cin>>n;
    cin.ignore();
    vector <string> s(n);
    for(ll i=0;i<n;i++)
      {
        string st;
        getline(cin,st);
        s[i]=st;
      }
     vector <bool> B(str.length(),false);
     for(ll i=0;i<n;i++)
        KMP(str,s[i],B);
     string b35="";
     for(ll j=0;j<str.length();j++)
      {
        if(B[j]==true && (j==0||B[j-1]==false))
          b35+="<b>";
        b35+=str[j];
        if(B[j]==true&&(j==str.length()-1 || B[j+1]==false))
           b35+="</b>";
      }
      cout<<b35;
}