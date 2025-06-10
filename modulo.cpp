#include <bits/stdc++.h>
using namespace std;
long long p;
int b;
long long z;
int w = 8;

uint64_t modulo (uint64_t z, uint64_t p, uint64_t b) {
    int k = (int)(log(p) / log(b)) + 1;
     // Tính μ = floor(b^(2k) / p)
    uint64_t mu = (uint64_t)(pow(b, 2 * k) / p);
  // Bước 1: q̂ = (z / b^(k-1)) * μ / b^(k+1)
    uint64_t q1 = (z / (uint64_t)pow(b, k - 1) * mu) / (uint64_t)pow(b, k + 1);
    // Bước 2: r = (z mod b^(k-1)) - ((q̂ * p) mod b^(k-1))
    uint64_t bk1 = (uint64_t)pow(b, k - 1);
    uint64_t r = (z % bk1) - ((q1 * p) % bk1);

    // Bước 3: Nếu r < 0 thì r += b^(k-1)
    if ((int64_t)r < 0) {
        r += bk1;
    }
    // Bước 4: while r >= p do r -= p
    while (r >= p) {
        r -= p;
    }
    // Bước 5: return r
    return r;
}

int main()
{
    long long p;
    int b;
    int k=log(p)/log(b)+1;
    long long z;
    long long u;



}