// using sparse table

#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> ar, lg(100005);
vector<vector<int>> spt;
void build()
{
    spt = vector<vector<int>>(n + 1, vector<int>(log2(n) + 1, -1));
    for (int i = 1; i <= n; i++)
        spt[i][0] = ar[i - 1];
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j + (1 << (i - 1)) <= n)
                spt[j][i] = min(spt[j][i - 1], spt[j + (1 << (i - 1))][i - 1]);
}
int query(int l, int r)
{
    int lgg = lg[r - l + 1];
    return min(spt[l][lgg], spt[r - (1 << lgg) + 1][lgg]);
}
void solve()
{
    cin >> n >> q;
    ar = vector<int>(n);
    for (auto &i : ar)
        cin >> i;
    build();
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[0] = lg[1] = 0;
    for (int i = 2; i <= 100000; i++)
        lg[i] = lg[i / 2] + 1;
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}