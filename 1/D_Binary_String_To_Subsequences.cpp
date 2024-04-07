#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> st;
    vector<int> lz, lo;
    int cnt = 0;
    if (s[0] == '0')
        lz.push_back(0);
    else
        lo.push_back(0);
    st.push_back({0});
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (lo.size())
            {
                int tm = lo.back();
                st[tm].push_back(i);
                lz.push_back(tm);
                lo.pop_back();
            }
            else
            {
                st.push_back({i});
                lz.push_back(st.size() - 1);
            }
        }
        else
        {
            if (lz.size())
            {
                int tm = lz.back();
                st[tm].push_back(i);
                lo.push_back(tm);
                lz.pop_back();
            }
            else
            {
                st.push_back({i});
                lo.push_back(st.size() - 1);
            }
        }
    }
    cout << st.size() << "\n";
    vector<int> ans(n);
    for (int i = 0; i < st.size(); i++)
        for (auto j : st[i])
            ans[j] = i + 1;
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
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