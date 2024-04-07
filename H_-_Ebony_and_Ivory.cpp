#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int lim = c / b;
    for (int i = 0; i <= lim; i++)
        if (!((c - i * b) % a))
        {
            cout << "Yes\n";
            return;
        }
    cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}