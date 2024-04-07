#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int m, tot = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        tot = (tot + x) % n;
    }
    cout << a[tot] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}