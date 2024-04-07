#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n <= 3 && m <= 3)
        cout << (n + 1) / 2 << " " << (m + 1) / 2 << "\n";
    else
        cout << "1 1\n";
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