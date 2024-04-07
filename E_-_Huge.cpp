#include <bits/stdc++.h>
using namespace std;
vector<string> mp;
int n, m, x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
bool valid(int i, int j)
{
    return i >= 0 && i < n;
}
int dfs(int u, int v)
{
    mp[u][v] = 'w';
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nu = u + x[i];
        int nv = (v + y[i] + m) % m;
        if (valid(nu, nv))
        {
            if (mp[nu][nv] == 'l')
                cnt += dfs(nu, nv);
        }
    }
    return cnt + 1;
}
void solve()
{
    while (cin >> n >> m)
    {
        mp = vector<string>(n);
        set<char> st;
        for (auto &s : mp)
            cin >> s;
        for (auto s : mp)
            for (auto c : s)
                st.insert(c);
        int u, v;
        cin >> u >> v;
        char c = mp[u][v];
        map<char, char> cv;
        cv[c] = 'l';
        st.erase(c);
        if (st.size())
            cv[*st.begin()] = 'w';
        for (auto &s : mp)
            for (auto &c : s)
                c = cv[c];
        dfs(u, v);
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] == 'l')
                    ans = max(ans, dfs(i, j));
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