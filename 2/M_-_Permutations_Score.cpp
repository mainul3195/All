#include <bits/stdc++.h>
using namespace std;
// complexity: O(n)
// Must call precalcRead it first
#define max_lim 100005
#define Mod 1000000007
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod - 2);
}
vector<long long> f(max_lim + 1);
void precalc()
{
    f[0] = 1;
    for (long long i = 1; i <= max_lim; i++)
        f[i] = f[i - 1] * i % Mod;
}
long long factorial(long long n)
{
    return f[n];
}
vector<long long> ans(100005), nod(100005);
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    ans[1] = 0;
    long long div2 = modInverse(2);
    for (int i = 1; i <= 100000; i++)
    {
        for (int j = i + i; j <= 100000; j += i)
            nod[j]++;
    }
    // for (int i = 0; i <= 30; i++)
    //     cout << i << " -> " << nod[i] << "\n";
    for (long long i = 2; i <= 100000; i++)
    {
        ans[i] = (ans[i - 1] * i + factorial(i) * nod[i] % Mod * div2) % Mod;
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}