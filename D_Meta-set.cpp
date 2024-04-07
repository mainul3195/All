#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<vector<int>> v(n, vector<int>(l));
    vector<int> count(n, 0);
    map<vector<int>, int> mp;
    for (auto &i : v)
    {
        for (auto &j : i)
            cin >> j;
        mp[i] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                vector<int> t(l);
                for (int k = 0; k < l; k++)
                {
                    int nm = (v[i][k] != v[j][k]) ? (((~(v[i][k] | v[j][k])) & (1 << 1)) + ((~(v[i][k] ^ v[j][k])) & 1)) : v[i][k];
                    t[k] = nm;
                }
                if (mp.count(t))
                    count[i]++;
            }
    long long ans = 0;
    for (auto &i : count)
    {
        i /= 2;
        ans += i * (i - 1) / 2;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}