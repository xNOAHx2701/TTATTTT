#include <bits/stdc++.h>
using namespace std;
#define ll long long
string UP(const string a)
{
    string A="";
    for(ll i=0;i<a.length();i++)
     {
        if(a[i]>='A'&&a[i]<='Z')
         A+=a[i];
     }
     return A;
}
int main()
{
    ll n;
    vector <string> s;
    string p;
    cin>>n;
    for(ll i=0;i<n;i++)
     {
        string str;
        cin>>str;
        string S=UP(str);
        s.push_back(S);
     }
    cin>>p;
   for(ll i=0;i<n;i++)
    {
        if(s[i]==p) cout<<"true\n";
        else cout<<"false\n";
    } 
    return 0;
}