#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<long long> v;
void solve()
{
    cin >> n >> q;
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];
    while (q--)
    {
        long long x;
        cin >> x;
        cout << (upper_bound(v.begin(), v.end(), x) - v.begin()) << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}