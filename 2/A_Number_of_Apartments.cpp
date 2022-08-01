#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 4)
        cout << "-1\n";
    else
    {
        int r = n % 3;
        if (r == 1)
            cout << (n - 7) / 3 << " 0 1\n";
        else if (r == 0)
            cout << n / 3 << " 0 0\n";
        else
            cout << (n - 5) / 3 << " 1 0\n";
    }
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