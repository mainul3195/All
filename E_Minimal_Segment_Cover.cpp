#include <bits/stdc++.h>
using namespace std;
int n, m, mx = 0, mxe = -1;
vector<int> E;
int lst[500005];
vector<vector<int>> sparse_table;
void solve()
{
    cin >> n >> m;
    vector<pair<int, int>> sg(n);
    for (auto &[l, r] : sg)
    {
        cin >> l >> r;
        mx = max(mx, l);
        mxe = max(mxe, r);
    }
    memset(lst, -1, sizeof(lst));
    E = vector<int>(mxe + 2, 0);
    for (auto [l, r] : sg)
        lst[l] = max(lst[l], r);
    for (int i = 0; i <= mx; i++)
        if (lst[i] != -1)
            E[lst[i]]++;
    multiset<int> st;
    for (int i = 0; i <= mxe; i++)
    {
        if (lst[i] != -1)
            st.insert(lst[i]);
        if (st.size())
            lst[i] = *st.rbegin();
        while (E[i])
        {
            st.erase(st.find(i));
            E[i]--;
        }
    }
    int lim = log2(500003 + .5);
    sparse_table = vector<vector<int>>(500003, vector<int>(lim + 1, -1));
    for (int i = 0; i <= mxe; i++)
        sparse_table[i][0] = lst[i];
    for (int k = 1; k <= lim; k++)
        for (int i = 0; i <= 500002; i++)
        {
            if (sparse_table[i][k - 1] == -1 || sparse_table[i][k - 1] == sparse_table[sparse_table[i][k - 1]][k - 1])
                sparse_table[i][k] = -1;
            else
                sparse_table[i][k] = sparse_table[sparse_table[i][k - 1]][k - 1];
        }
    // for (int i = 0; i <= 6; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j <= 4; j++)
    //         cout << sparse_table[i][j] << " ";
    //     cout << "\n";
    // }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = lim; i >= 0; i--)
        {
            if (sparse_table[l][i] != -1 && sparse_table[l][i] <= r)
            {
                ans += (1 << i);
                l = sparse_table[l][i];
                if (l == r)
                    break;
            }
        }
        if (sparse_table[l][0] == -1 || (l < r && l == sparse_table[l][0]))
            ans = -1;
        if (sparse_table[l][0] > r && l != r)
            ans++;
        cout << ans << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}