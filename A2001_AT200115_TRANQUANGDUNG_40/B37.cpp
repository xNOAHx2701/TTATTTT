#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool lap(string &s,const string &p)
{
  if(s.length()!=p.length()) return false;
   for(ll i=0;i<s.length()-1;i++)
   {
    s+=s[0];
    s.erase(0,1);
    if(s==p) return true;
   }
  return false;
}

int main()
{
    string s,p;
    getline(cin,s);
    getline(cin,p);
    if(lap(s,p)) cout<<"true";
    else cout<<"false";
    return 0;
}