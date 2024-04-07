#include <bits/stdc++.h>
using namespace std;
vector<long long> seg;
void solve()
{
    long long n;
    cin >> n;
    int ind = lower_bound(seg.begin(), seg.end(), n) - seg.begin();
    cout << (char)((n - 1 - seg[ind - 1]) / ind + 'A') << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    seg.push_back(0);
    for (int i = 0; i < 300000; i++)
        seg.push_back(seg.back() + 26);
    for (int i = 1; i < seg.size(); i++)
        seg[i] += seg[i - 1];
    // cout << seg.back() << "\n";
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}