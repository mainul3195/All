#include <bits/stdc++.h>
using namespace std;
int n, tc = 0;
void solve()
{
    // taking input and making adjacency list
    vector<vector<int>> adj(21, vector<int>());

    while (n--)
    {
        int v;
        cin >> v;
        adj[1].push_back(v);
        adj[v].push_back(1);
    }
    for (int u = 2; u < 20; u++)
    {
        cin >> n;
        while (n--)
        {
            int v;
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    cout << "Test Set #" << ++tc << "\n";
    // //processing each query
    int q;
    cin >> q;
    while (q--)
    {
        int start, end;
        vector<int> level(21, -1);
        cin >> start >> end;
        queue<int> q;
        q.push(start);
        level[start] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();
            if (u == end)
            {
                cout << setw(2) << start;
                cout << " to ";
                cout << setw(2) << end;
                cout << ": " << level[u] << "\n";
                break;
            }
            for (auto v : adj[u])
                if (level[v] == -1)
                {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
        }
    }
    cout << "\n";
    return;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    while (cin >> n)
        solve();
    return 0;
}