#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> visited;
int n, t;
void solve()
{
    cin >> n >> t;
    adj = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        adj[i].push_back(i + a);
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