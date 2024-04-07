#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.second > b.second || (a.second == b.second && a.first > b.first);
}
void solve()
{
    cin >> n;
    vector<pair<long long, long long>> mat(n);
    for (auto &[a, b] : mat)
        cin >> a;
    for (auto &[a, b] : mat)
        cin >> b;
    cin >> m;
    vector<pair<long long, long long>> phy(m);
    for (auto &[a, b] : phy)
        cin >> a;
    for (auto &[a, b] : phy)
        cin >> b;
    sort(mat.begin(), mat.end(), cmp);
    sort(phy.begin(), phy.end(), cmp);
    long long tot_iq = 0, tol = n, ans = 0, taken = 0;
    int i = 0;
    while (1)
    {
        vector<long long> v;
        for (auto [a, b] : mat)
        {
            if (b >= taken)
                v.push_back(a);
            else
                break;
        }
        sort(v.rbegin(), v.rend());
        while (v.size() > tol)
            v.pop_back();
        long long tmp = 0;
        for (auto el : v)
            tmp += el;
        ans = max(ans, tot_iq + tmp);
        if (i == m)
            break;
        tot_iq += phy[i].first;
        tol = min(tol, phy[i].second);
        i++;
        taken++;
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
