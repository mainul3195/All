#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nd
{
    int t, val;
    bool operator<(const nd &a) const
    {
        return val > a.val || (val == a.val && t > a.t);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<nd> op(m);
    for (auto &[t, val] : op)
        cin >> t >> val;
    sort(op.begin(), op.end());
    sort(v.begin(), v.end());
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    // for (auto [t, val] : op)
    //     cout << t << " " << val << "\n";
    int opind = 0, tind = 0, mnind = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= op[opind].val)
            break;
        v[i] = op[opind].val;
        if (!(--op[opind].t))
            opind++;
        if (opind == op.size())
            break;
    }
    int sum = 0;
    for (auto i : v)
        sum += i;
    cout << sum << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}