#include <bits/stdc++.h>
using namespace std;

void solve()
{
    pair<int, int> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    if (a > b)
        swap(a, b);
    if (b.first <= a.second)
        cout << b.first << "\n";
    else
        cout << a.first + b.first << "\n";
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