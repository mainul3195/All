#include <bits/stdc++.h>
using namespace std;
vector<int> child, par, root, child_count;
int getroot(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = getroot(root[u]);
}
void bef(int cur)
{
    for (int i = 0; i < 26; i++)
        if (child[i] == -1)
        {
            int rc = getroot(cur);
            int ri = getroot(i);
            if (rc != ri || (rc == ri && child_count[rc] == 26))
            {
                child[i] = cur;
                par[cur] = i;
                root[rc] = ri;
                child_count[ri] += child_count[rc];
                child_count[rc] = 0;
                return;
            }
        }
    return;
}
void solve()
{
    child = vector<int>(26, -1);
    par = vector<int>(26, -1);
    root = vector<int>(26, -1);
    for (int i = 0; i < 26; i++)
        root[i] = i;
    child_count = vector<int>(26, 1);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto c : s)
        if (par[c - 'a'] == -1)
            bef(c - 'a');
    for (auto c : s)
        cout << (char)(par[c - 'a'] + 'a');
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