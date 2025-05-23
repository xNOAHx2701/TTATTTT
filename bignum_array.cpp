#include <bits/stdc++.h>
using namespace std;
long long a;
vector <int> A;
int main()
{
    int w;
    long f;
   // cout<<"nhap W, F:"  ;
    //cin>>w>>f;
    int t;
    cin>>w>>t;
    cout<<"nhap A";
    cin>>a;
    //double t=log2(f)/w;
    //t=round(t);
    for(int i=t-1;i>=0;i--)
     {
        int e=a/pow(2,w*i);
        A.push_back(e);
        a=a-e*pow(2,w*i);
     }
    for(int j=0;j<A.size();j++)
     {cout<<A[j]<<" ";}
    
    return 0;
}