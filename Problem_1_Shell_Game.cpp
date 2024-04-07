#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int pos[4] = {0, 1, 2, 3}, ans[4] = {0};
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, g;
        cin >> a >> b >> g;
        swap(pos[a], pos[b]);
        ans[pos[g]]++;
    }
    cout << max({ans[1], ans[2], ans[3]}) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    solve();
    return 0;
}