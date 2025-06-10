#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;
    ll n = -1;
    for (ll i = 0; i < a.length();++i)
    {   
        if (b[0] == a[i])
        {   ll j=0;
            ll y=i;
            n = 1;
            while (b[j] == a[y])
            {
                ++j;
                if (y + 1 >= a.length())
                {
                    y = y + 1 - a.length();
                    n++;
                }
                else
                    ++y;
            }
            if (j < b.size())
                n = -1;
            else break;
        }
    }
    //abc bac
    cout << n;
    return 0;
}