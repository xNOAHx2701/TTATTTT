#include <bits/stdc++.h>
using namespace std;
#define ll long long

string chuanhoa(const string &s)
{
    ll dd[29] = {0};
    ll d = 1;
    string n ="";
    for (ll i = 0; i < s.size(); ++i)
    {  
        if (dd[s[i] - 97] == 0)
        {
          dd[s[i] - 97] = d;
            n = n + char(dd[s[i] - 97] + 48);
            ++d;
        }
        else
            n = n + char(dd[s[i] - 97] + 48);
    }
    return n;
}

int main()
{
   vector <string> F;
   string p;
   ll n;
   cin>>n;
   cin.ignore();
   for(ll i=0; i<n;i++)
   {
     string s;
     getline(cin,s);
     F.push_back(s);
   }
   getline(cin,p);
   string P=chuanhoa(p);
   for(ll i=0;i<F.size();i++)
   {
    if(chuanhoa(F[i])==P) cout<<F[i]<<" ";
   }
   return 0;
}