#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long p, l;
    cin >> p >> l;
    long long n = p - l;
    vector<long long> divisors;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    sort(divisors.rbegin(), divisors.rend());
    while (divisors.size() && divisors.back() < l)
        divisors.pop_back();
    if (!divisors.size())
        cout << "impossible\n";
    else
    {
        while (divisors.size())
        {
            cout << divisors.back() << " ";
            divisors.pop_back();
        }
        cout << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}