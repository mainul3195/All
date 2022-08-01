#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    for (long long i = 0; i < n; i++)
        v[i] = v[n - 1] - v[i];
    long long even = 0, odd = 0;
    for (auto i : v)
    {
        even += i / 2;
        odd += i % 2;
    }
    // cout << even << " " << odd << "\n";
    if (odd < even)
    {
        long long dif = even - odd;
        long long dec = (dif + 1) / 3;
        even -= dec;
        odd += 2 * dec;
    }

    for (auto &i : v)
        i++;
    long long even2 = 0, odd2 = 0;
    for (auto i : v)
    {
        even2 += i / 2;
        odd2 += i % 2;
    }
    // cout << even2 << " " << odd2 << "\n";
    if (odd2 < even2)
    {
        long long dif = even2 - odd2;
        long long dec = (dif + 1) / 3;
        even2 -= dec;
        odd2 += 2 * dec;
    }
    cout << min(max(2 * even, 2 * odd - 1), max(2 * even2, 2 * odd2 - 1)) << "\n";
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