#include <bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> cur(3, 0), prev(3, 0);
    int n;
    cin >> n;
    cin >> cur[0] >> cur[1] >> cur[2];
    n--;
    while (n--)
    {
        prev = cur;
        cin >> cur[0] >> cur[1] >> cur[2];
        cur[0] += min(prev[1], prev[2]);
        cur[1] += min(prev[0], prev[2]);
        cur[2] += min(prev[0], prev[1]);
    }
    cout << min({cur[0], cur[1], cur[2]}) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}