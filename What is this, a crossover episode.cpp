#include<bits/stdc++.h>
using namespace std;
vector<int>node[100000], par(10004), col(10004);
int fmn(int a, int b)
{
    int i;
    for(i=1; i==a || i==b; i++);
    return i;
}
int asncol(int n)
{
    set<int> s;
    for(auto i: node[n])
        s.insert(col[i]);
    if(*s.begin()==0)
        s.erase(s.begin());
    s.insert(2000000000);
    for(int i=1; ; i++)
    {
        if(i!=*s.begin())
        return i;
        s.erase(s.begin());
    }
}
int bfs()
{
    queue<int> q;
    q.push(1);
    col[1]=1;
    par[1]=0;
    int mx = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto i: node[u])
        {
            if(i==u)
                continue;
            int f=0;
            if(!col[i])
            {
                q.push(i);
                par[i]=u;
                col[i]=asncol(i);
            }
            else if(col[i]==col[u])
            {
                f=asncol(i);
                col[i]=f;
            }
            mx = max(mx, col[i]);
        }
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++)
        node[i].clear();
    for(int i=1; i<n; i++)
    {
        node[i].push_back(i+1);
        node[i+1].push_back(i);
    }
    for(int i=0; i<m; i++)
    {
        int j,k;
        cin >> j >> k;
        node[j].push_back(k);
        node[k].push_back(j);
    }
    node[n].push_back(1);
    node[1].push_back(n);
    fill(par.begin(), par.end(), 0);
    fill(col.begin(), col.end(), 0);
    // for(int i=1; i<=4; i++)
    // {
    //     for(auto j: node[i])
    //     cout << j << " ";
    //     cout << "\n";
    // }
    cout << bfs() << "\n";
    // for(int i=1; i<=n; i++)
    //     cout << par[i] << " \n"[i==n];
    for(int i=1; i<=n; i++)
        cout << col[i] << " \n"[i==n];
    return 0;
}