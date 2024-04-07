#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<string, string> child;
    map<string, int> indegree;
    for (int i = 1; i < n; i++)
    {
        string u, v;
        cin >> u >> v;
        child[u] = v;
        indegree[v]++;
        indegree[u] = indegree[u];
    }
    for (auto [_, ind] : indegree)
        if (!ind)
        {
            string s = _;
            cout << s << "\n";
            while (child.count(s))
            {
                s = child[s];
                cout << s << "\n";
            }
            break;
        }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Scenario #" << ++tc << ":\n";
        solve();
    }
    return 0;
}