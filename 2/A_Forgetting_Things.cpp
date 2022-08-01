#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2)
        cout << d1 << "1 " << d2 << "2\n";
    else if (d1 + 1 == d2)
        cout << d1 << "9 " << d2 << "0\n";
    else if (d1 == 9 && d2 == 1)
        cout << d1 << " " << d2 << "0\n";
    else
        cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}