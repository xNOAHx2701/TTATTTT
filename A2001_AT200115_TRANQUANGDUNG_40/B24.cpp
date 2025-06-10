#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool sosanh(const string &T, const string &P)
{
    ll t=0,p=0, dd=-1, match=0;
    while(t<T.length())
    {
        if(p<P.length()&&(P[p]=='?' || P[p]==T[t]))
          {t++;p++;}
        else if(p<P.length()&&P[p]=='*')
            {
                dd=p;
                match=t;
                p++;
            }
             else if(dd!=-1){
                p=dd+1;
                match++;
                t=match;
                }
                else return false;

    }
    while (p<P.length()&&P[p]=='*') p++;
    return p==P.length();
}
int main()
{   string t,p;
    cin>>t;
    cin>>p;
    ll n=t.length();
    ll m=p.length();
    if(sosanh(t,p)) cout<<"true";
    else cout<<"false";
    return 0;
}