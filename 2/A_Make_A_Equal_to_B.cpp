#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int dif = 0, a1 = 0, a0 = 0, b1 = 0, b0 = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            if (a[i] == 1)
                a1++, b0++;
            else
                a0++, b1++;
            dif++;
        }
    if (a0 == 0 || a1 == 0)
        cout << dif << "\n";
    else
        cout << 1 + abs(a0 - a1) << "\n";
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