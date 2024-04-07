#include <bits/stdc++.h>
using namespace std;
#define changeBit(i) (f[(i) / 32] |= (1 << ((i) % 32)))
#define checkBit(i) (f[(i) / 32] & (1 << ((i) % 32)))
#define lim 10000000
int f[lim / 32 + 1];
vector<int> primes;
void sieve()
{
    for (int i = 4; i <= lim; i += 2)
        changeBit(i);
    for (int i = 3; i * i <= lim; i += 2)
        if (!checkBit(i))
            for (int j = i * i; j <= lim; j += 2 * i)
                changeBit(j);
    for (int i = 2; i <= lim; i++)
        if (!checkBit(i))
            primes.push_back(i);
}
void solve()
{
    int n;
    cin >> n;
    int mid = n / 2;
    int ans = 0;
    for (int i = 0; primes[i] <= mid; i++)
        if (!checkBit(n - primes[i]))
            ans++;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}