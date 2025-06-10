#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll failure(const string &P)
{
    ll j=P.size();
    ll i=j/2;
    while(P.substr(0,i)!=P.substr(j-i,i)&&i>0)
          i--;
    return i;
}
int main()
{
    string p;
    getline(cin,p);
    cout<<failure(p);
    return 0;
}