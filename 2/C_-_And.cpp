#include <bits/stdc++.h>
using namespace std;
#define inf 1000000
int adj[103][103];
void solve()
{
    for (int i = 0; i < 103; i++)
        for (int j = 0; j < 103; j++)
            adj[i][j] = inf;
    int tc = 0;
    int a, b;
    int mx = 0;
    set<int> st;
    while (cin >> a >> b && (a || b))
    {
        st.insert(a);
        st.insert(b);
        adj[a][b] = 1;
        mx = max({mx, a, b});
        while (cin >> a >> b && (a || b))
        {
            st.insert(a);
            st.insert(b);
            adj[a][b] = 1;
            mx = max({mx, a, b});
        }

        for (int k = 1; k <= mx; k++)
            for (int i = 1; i <= mx; i++)
                for (int j = 1; j <= mx; j++)
                    if (i != j)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        double tot = 0;
        for (int i = 1; i <= mx; i++)
            for (int j = 1; j <= mx; j++)
                if (adj[i][j] != inf)
                    tot += adj[i][j];
        int nd = st.size();
        cout << fixed << setprecision(3) << "Case " << ++tc << ": average length between pages = " << tot / (nd * (nd - 1)) << " clicks\n";
        for (int i = 0; i <= mx; i++)
            for (int j = 0; j <= mx; j++)
                adj[i][j] = inf;
        mx = 0;
        st.clear();
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