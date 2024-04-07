#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
struct mat
{
    long long a, b, c, d;
    mat operator*(mat x)
    {
        return {(a * x.a + b * x.c) % mod, (a * x.b + b * x.d) % mod, (c * x.a + d * x.c) % mod, (c * x.b + d * x.d) % mod};
    }
};
mat fb = {1, 1, 1, 0}, identity = {1, 0, 0, 1};
mat fibo(int p)
{
    if (!p)
        return identity;
    if (p & 1)
        return fb * fibo(p - 1);
    mat tmp = fibo(p / 2);
    return tmp * tmp;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << (fibo(m + 1).a - fibo(n).a + mod) % mod << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}