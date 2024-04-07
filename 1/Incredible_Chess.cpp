#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> w(n), b(n);
    for (auto &i : w)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int Xor = 0;
    for (int i = 0; i < n; i++)
        Xor ^= (b[i] - w[i] - 1);
    if (Xor)
        cout << "white wins\n";
    else
        cout << "black wins\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}