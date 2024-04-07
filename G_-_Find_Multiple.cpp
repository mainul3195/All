#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    if (a > b)
        a ^= b ^= a ^= b;
    cin >> a >> b >> c;
    int ans = (a + c - 1) / c * c;
    cout << (ans <= b ? ans : -1) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}