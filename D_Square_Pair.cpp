#include <bits/stdc++.h>
using namespace std;
#define lim 300005
bitset<lim / 2 + 2> bit;
vector<long long> primes;
void make_primes()
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (auto &i : v)
    {
        if (i == 0)
            continue;
        int nw = 1;
        for (auto p : primes)
        {
            if (p * p > i)
                break;
            int cnt = 0;
            while (i % p == 0)
            {
                cnt++;
                i /= p;
            }
            if (cnt & 1)
                nw *= p;
        }
        if (i > 1)
            nw *= i;
        i = nw;
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (auto i : v)
    {
        if (i == 0)
        {
            ans += n - 1;
            continue;
        }
        ans += upper_bound(v.begin(), v.end(), i) - lower_bound(v.begin(), v.end(), i) - 1;
        ans += upper_bound(v.begin(), v.end(), 0) - lower_bound(v.begin(), v.end(), 0);
    }
    cout << ans / 2 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_primes();
    solve();
    return 0;
}