#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> done;
vector<int> now_riding_at, done_count, que;
int n, m;
int ride_done, tot;
long long time_passed;
void init()
{
    done = vector<vector<int>>(n, vector<int>(m, 0));
    now_riding_at = vector<int>(m, -1);
    done_count = vector<int>(n, 0);
    que.clear();
    for (int i = 0; i < n; i++)
        que.push_back(i);
    ride_done = 0, tot = n * m;
    time_passed = 0;
    return;
}
void get_inside(int cur)
{
    for (int i = 0; i < que.size(); i++)
        if (!done[que[i]][cur])
        {
            now_riding_at[cur] = que[i];
            que.erase(que.begin() + i);
            return;
        }
}
void get_out(int cur)
{
    done[now_riding_at[cur]][cur] = 1;
    done_count[now_riding_at[cur]]++;
    if (done_count[now_riding_at[cur]] < m)
        que.push_back(now_riding_at[cur]);
}
void solve()
{
    cin >> n >> m;
    init();
    int cur = 0;
    int cnt = 0;
    while (ride_done < tot)
    {
        time_passed += 5;
        if (now_riding_at[cur] == -1)
            get_inside(cur);
        else
        {
            ride_done++;
            get_out(cur);
            now_riding_at[cur] = -1;
            get_inside(cur);
        }
        cur = (cur + 1) % m;
    }
    cout << time_passed << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}