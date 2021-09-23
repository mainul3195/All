#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>v;
vector<int> low_time, discovery_time, parent, visited, level;
vector<vector<int>>new_graph;
map<pair<int, int>, bool> done;
int curtime, n, m, ans;

void mark(int u, int par=-1)
{
    low_time[u] = discovery_time[u] = ++curtime;
    for(auto i: v[u])
    {
        if(i==par) continue;

        if(discovery_time[i])
            low_time[u] = min(low_time[u], discovery_time[i]);
        else 
        {
            mark(i, u);
            low_time[u] = min(low_time[u], low_time[i]);
        }
        if(low_time[i]<=discovery_time[u])
            new_graph[i].push_back(u), new_graph[u].push_back(i);
    }
}

// 0 if not, 1 otherwise
bool isBipartide(int u, int p = -1, int l=1)
{
    visited[u] = l;
    for(auto i: new_graph[u])
    {
        if(visited[i])
        {
            if(i!=p && visited[i]%2 == visited[u]%2)
                return 0;
            continue;
        }
        if(!isBipartide(i, u, l+1)) return 0;
    }
    return 1;
}

int nodecount(int u)
{
    visited[u] = -2;
    int tot = 0;
    for(auto i:new_graph[u])
        if(visited[i] != -2)
            tot += nodecount(i);
    return tot+1;
}
void clearall()
{
    visited.clear();
    level.clear();
    new_graph.clear();
    v.clear();
    parent.clear();
    discovery_time.clear();
    low_time.clear();
    done.clear();
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, tc;
    cin >> t;
    for(tc = 1; tc<=t; tc++)
    {
        ans = curtime = 0;

        cin >> n >> m;
        for(int i=0; i<n; i++)
            parent.push_back(i);

        v = vector<vector<int>>(n, vector<int>());
        visited = vector<int>(n, 0);
        discovery_time  = vector<int>(n, 0);
        low_time  = vector<int>(n, 0);

        while(m--)
        {
            int i, j;
            cin >>  i >> j;
            v[i].push_back(j);
            v[j].push_back(i);
        }
        new_graph = vector<vector<int>>(n);


        for(int i=0; i<n; i++)
            if(!discovery_time[i])
                mark(i);


        visited = vector<int>(n, 0);
        for(int i=0; i<n; i++)
            if(!visited[i] && !isBipartide(i))
            {
                int tmp = nodecount(i);
                if(tmp != 1)
                    ans += tmp;
            }

        cout << "Case " << tc << ": " << ans << "\n";
        clearall();

    }
    return 0;
}