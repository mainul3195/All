#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    for (long long i = 1; i < n; i++)
        v[i] += v[i - 1];

    long long tot = 0, days = 0;
    for (long long i = n - 1; i >= 0; i--)
    {
        long long tmp = v[i] + (i + 1) * days, count = 0;
        if (tmp > x)
            continue;
        // cout << tmp << " ";
        count = 1 + (x - tmp) / (i + 1);
        days += count;
        tot += (i + 1) * count;
        // cout << count << " " << days << " " << tot << "\n";
    }
    cout << tot << "\n";
    // cout << "\n\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}