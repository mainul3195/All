#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (x == y && y == z)
    {
        cout << "YES\n";
        cout << x << " " << x << " " << x << "\n";
    }
    else if (x == z && y < x)
    {
        cout << "YES\n";
        cout << x << " " << y << " " << y << "\n";
    }
    else if (y == z && x < y)
    {
        cout << "YES\n";
        cout << y << " " << x << " " << x << "\n";
    }
    else if (x == y && z < x)
    {
        cout << "YES\n";
        cout << x << " " << z << " " << z << "\n";
    }
    else
        cout << "NO\n";
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