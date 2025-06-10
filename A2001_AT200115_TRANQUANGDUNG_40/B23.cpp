#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   string s;
   cin>>s;
   ll n=0;
   ll i=0;
   while(i<s.length())
   {
    if(s[i]=='1'&&s[i+1]=='0')
     {
      while(s[i+1]=='0') i++;
       if(s[i+1]=='1') n++;
       i++;
     }
    i++;
   }
   cout<<n;
   return 0;
}