#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool kt(const string &s, const string &p,ll k)
{   if(s.length()<k) return false;
    for(ll i=0;i<k;i++)
     if(s[i]!=p[i]) return false;
    return true;
}

int main()
{
    ll k,n;
    vector <string> arr;
    string s;
    ll d=0;
    cin>>k>>n;
    cin.ignore();
    for(ll i=0;i<n;++i)
    {
        string str;
        getline(cin,str);
        arr.push_back(str);
    }
    getline(cin,s);
    if(k>=s.length()) cout<<0;
    else{
        for(ll i=0;i<n;i++)
         if(kt(arr[i],s,k)) d++;
        cout<<d;
    }
  return 0;
}