#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << i / 2 + 1 << " ";
        else
            cout << n - i / 2 << " ";
    }
    cout << "\n";
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