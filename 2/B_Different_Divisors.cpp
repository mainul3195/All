#include <bits/stdc++.h>
using namespace std;
#define lim 10000000

#define ckbit(x) (fLd[(x) / 64] & (1 << ((x) % 64) / 2))
#define cngbit(x) (fLd[(x) / 64] |= (1 << ((x) % 64) / 2))
int fLd[lim / 64 + 2];
vector<long long> prime;
void sieve()
{
    prime.push_back(2);
    for (long long i = 3; i * i <= lim; i += 2)
        if (!ckbit(i))
            for (long long j = i * i; j <= lim; j += 2 * i)
                cngbit(j);
    for (long long i = 3; i <= lim; i += 2)
        if (!ckbit(i))
            prime.push_back(i);
    return;
}
void solve()
{
    int n;
    cin >> n;
    int a = *lower_bound(prime.begin(), prime.end(), 1 + n);
    int b = *lower_bound(prime.begin(), prime.end(), a + n);
    // cout << a << " " << b << "\n";
    cout << a * b << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}