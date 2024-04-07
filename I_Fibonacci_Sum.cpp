#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
struct mat
{
    long long a, b, c, d;
    mat operator*(const mat &t)
    {
        return {
            (a * t.a + b * t.c) % mod,
            (a * t.b + b * t.d) % mod,
            (c * t.a + d * t.c) % mod,
            (c * t.b + d * t.d) % mod};
    }
};
mat base = {1, 1, 1, 0}, identity = {1, 0, 0, 1};
mat Pow(int p)
{
    if(!p)
        return identity;
    if(p&1)
        return base*Pow(p-1);
    mat tmp = Pow(p/2);
    return tmp*tmp;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << (Pow(m+1).a - Pow(n).a+mod)%mod << "\n";
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