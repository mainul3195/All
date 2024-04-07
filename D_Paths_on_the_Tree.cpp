#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> c, s;
vector<vector<int>> adj;
map<pair<int, long long>, long long> mp;

// long long mx(vector<pair<long long, long long>> &v, )
long long find(int p, int u, long long c)
{
    // cout << u << " " << c << endl;
    if (!c)
        return 0;
    if (mp.count({u, c}))
        return mp[{u, c}];
    long long tot = 0;
    multiset<pair<long long, long long>> st;
    int child = adj[u].size();
    if (u)
        child--;

    if (child)
    {
        int rem = c % child;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            long long frst = find(u, v, c / child);
            long long snd = rem ? find(u, v, c / child + 1) : frst;
            st.insert({snd, frst});
        }
        // int deletable = child - rem;
        vector<pair<long long, long long>> v(st.begin(), st.end());
        vector<long long> cum1(v.size() + 1, 0), cum0(v.size() + 1, 0);
        for (int i = 1; i <= v.size(); i++)
        {
            cum0[i] = cum0[i - 1] + v[i - 1].second;
            cum1[i] = cum1[i - 1] + v[i - 1].first;
        }
        for (int i = v.size(); i >= rem; i--)
            tot = max(tot, cum1[i] - cum1[i - rem] + cum0[v.size()] - (cum0[i] - cum0[i - rem]));

        // for (int i = 0; i < deletable; i++)
        // {
        //     tot += (*st.begin()).second;
        //     st.erase(st.begin());
        // }
        // for (auto [a, b] : st)
        //     tot += a;
    }
    return mp[{u, c}] = tot + s[u] * c;
}
void solve()
{
    cin >> n >> k;
    adj.clear();
    mp.clear();
    adj = vector<vector<int>>(n, vector<int>());
    c = vector<long long>(n, -1);
    s = vector<long long>(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";
    //     for (auto j : adj[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }
    for (auto &i : s)
        cin >> i;
    // cout << "Here\n";
    cout << find(-1, 0, k) << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}