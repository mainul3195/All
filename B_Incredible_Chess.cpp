#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tot ^= x - v[i] - 1;
    }
    if (tot)
        cout << "white wins\n";
    else
        cout << "black wins\n";
    return;
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