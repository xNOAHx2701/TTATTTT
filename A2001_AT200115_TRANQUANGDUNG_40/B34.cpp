#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
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
    for(ll i=0;i<n;i++)
     {  ll k=1;
        for(ll j=0;j<n;j++) 
          {if(j!=i)
            while(s[i].substr(0,k)==s[j].substr(0,k))
              k++;
          }
        cout<<s[i].substr(0,k)<<" ";
     }
    return 0;
}