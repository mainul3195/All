#include<bits/stdc++.h>
using namespace std;
int n, x[]={0,1,0,-1}, y[]={1, 0, -1, 0};
pair<int, int> start;
vector<string> s(15);
int bfs(char e)
{
    queue<pair<int, int> > q;
    vector<vector<int> > dis(15, vector<int>(15, -1));
    q.push(start);
    dis[start.first][start.second]=0;
    while(!q.empty())
    {
        int u=q.front().first;
        int v=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int a=u+x[i];
            int b=v+y[i];
            if(a<0 || a>=n || b<0 || b>=n || s[a][b]=='#' || (s[a][b] <= 'Z' && s[a][b] >= 'A' && s[a][b]!=e) || dis[a][b]!=-1)
                continue;
            dis[a][b]=dis[u][v]+1;
            if(s[a][b]==e)
            {
                s[start.first][start.second]='.';
                start={a,b};
                return dis[a][b];
            }
            q.push({a,b});
        }
    }
    return 0;
}
int main()
{
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0 ; i<= n; i++)
            s[i].clear();
        for(int i=0; i<n; i++)
            cin >> s[i];
        char mx=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(s[i][j] <= 'Z' && s[i][j] >= 'A')
                {
                    if(s[i][j]=='A')
                        start={i,j};
                    mx = max(mx, s[i][j]);
                }
        mx-=64;
        int dis=0;
        bool ok=1;
        for(int i=1; i<mx; i++)
        {
            int temp = bfs(i+65);
            if(!temp)
            {
                ok=0;
                break;
            }
            dis+=temp;
        }
        cout << "Case " << ++tc << ": ";
        if(ok)
            cout << dis << "\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}