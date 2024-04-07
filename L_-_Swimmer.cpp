#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    int speed[n];
    for (int i = 0; i < n; i++)
        cin >> speed[i];
    while (q--)
    {
        int time, person;
        cin >> time >> person;
        int tot_dist = speed[person - 1] * time;
        tot_dist %= 2 * m;
        cout << (tot_dist <= m ? tot_dist : 2 * m - tot_dist) << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}