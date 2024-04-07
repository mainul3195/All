#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
bitset<1000006> b;
void sieve()
{
    for (int i = 3; i * i <= 1000000; i += 2)
        if (b[i / 2] == 0)
            for (int j = i * i; j <= 1000000; j += 2 * i)
                b[j / 2] = 1;
    primes.push_back(2);
    for (int i = 3; i <= 1000000; i += 2)
        if (!b[i / 2])
            primes.push_back(i);
    return;
}

void solve()
{
    long long n;
    cin >> n;
    vector<long long> prime_divisors;
    for (auto p : primes)
    {
        if (p * p > n)
            break;
        while (n % p == 0)
        {
            n /= p;
            prime_divisors.push_back(p);
        }
    }
    if (n > 1)
        prime_divisors.push_back(n);
    vector<long long> ans = {1};
    map<long long, bool> mp;
    for (auto d : prime_divisors)
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            long long tmp = ans[i] * d;
            if (!mp.count(tmp))
            {
                ans.push_back(tmp);
                mp[tmp] = 1;
            }
        }
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    sieve();
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}