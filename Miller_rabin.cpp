#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> bieudiennhiphan(ll k)
{
  vector<int> K;
  K.push_back((k & 1));
  while (k != 0)
  {
    K.push_back(((k >> 1) & 1));
    k = (k >> 1);
  }
  K.pop_back();
  return K;
}

ll binhphuongcolap(ll a, ll K, ll n)
{
  ll b = 1;
  ll A;
  vector<int> k = bieudiennhiphan(K);
  if (K == 0)
    return b;
  else
  {
    A = a;
    if (k[0] == 1)
      b = a;
    for (int i = 1; i < k.size(); i++)
    {
      A = (A * A) % n;
      if (k[i] == 1)
        b = (A * b) % n;
    }
    return b;
  }
}

ll random(ll n)
{
  srand((unsigned)time(NULL));
  ll r = rand() % (n - 3) + 2;
  return r;
}

bool Miller_rabin(ll n, ll t)
{
  if (n == 3 || n == 2)
    return true;
  ll r = n - 1;
  ll s = 0;
  while (r % 2 == 0)
  {
    r = (r >> 1);
    s++;
  }
  for (ll i = 0; i < t; i++)
  {
    ll a = random(n);
    ll y = binhphuongcolap(a, r, n);
    if (y != 1 && y != n - 1)
    {
      ll j = 1;
      while (j <= s - 1 && y != n - 1)
      {
        y = binhphuongcolap(y, 2, n);
        if (y == 1)
          return false;
        j++;
      }
      if (y != n - 1)
        return false;
    }
  }
  return true;
}

int main()
{
  ll n;
  cin >> n;
  if(Miller_rabin(n,3)==true) cout<<"nguyento";
  else cout<<"hopso";
  return 0;
}