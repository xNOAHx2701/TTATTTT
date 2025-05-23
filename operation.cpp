#include <bits/stdc++.h>
using namespace std;
long long a,b;
long p;
typedef string bignum_str;
typedef vector < int > vi;
void input(bignum_str &number)
{
    cin >> number;
}

void output(bignum_str number)
{
    cout << number; cout<<endl;
}

void equal_length(bignum_str &a, bignum_str &b)
{
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
}
bignum_str add(bignum_str a, bignum_str b)
{
    equal_length(a, b);
    
    int carry = 0;
    bignum_str res;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        // Cộng hai chữ số cùng hàng và thêm biến nhớ từ hàng bên phải dồn lên.
        int d = (a[i] - '0') + (b[i] - '0') + carry;
        
        carry = d / 10; // Biến nhớ bằng kết quả hàng trước chia 10.
        res = (char)(d % 10 + '0') + res; // Viết chữ số cuối của kết quả.
    }
    
    if (carry)
        res = '1' + res;
        
    return res;
}
int main()
{
   cout<<sizeof(long long);

    
    return 0;
}