#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int lim = 1 << (int)log2(n - .9);
    for (int i = n - 1; i >= lim; i--)
        cout << i << " ";
    for (int i = 0; i < lim; i++)
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