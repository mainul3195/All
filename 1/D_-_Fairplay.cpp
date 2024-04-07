#include <bits/stdc++.h>
using namespace std;
int square_root(int n)
{
    int sq = sqrt(n + .5);
    return (sq * sq == n ? sq : 0);
}
void solve()
{
    int n;
    cin >> n;
    int sq = square_root(n + 1);
    if (!sq)
    {
        cout << "-1\n";
        return;
    }
    cout << sq - 1 << "\n";
    for (int i = sq - 1; i; i--)
        cout << i << " ";
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