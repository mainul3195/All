#include <bits/stdc++.h>
using namespace std;
#define lim 1000006
bitset<lim / 2 + 2> bit;
vector<long long> primes;
void make_prime()
{
    primes.push_back(2);
    for (int i = 3; i * i < lim; i += 2)
        if (!bit[i / 2])
            for (int j = i * i; j < lim; j += 2 * i)
                bit[j / 2] = 1;
    for (int i = 3; i < lim; i += 2)
        if (!bit[i / 2])
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
    map<long long, int> found;
    for (auto f : prime_divisors)
    {
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            long long tmp = ans[i] * f;
            if (found.count(tmp) == 0)
            {
                ans.push_back(tmp);
                found[tmp] = 1;
            }
        }
    }
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_prime();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}