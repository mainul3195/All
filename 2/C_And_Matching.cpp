#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    if (n == 4 && k == 3)
    {
        cout << "-1\n";
        return;
    }

    set<int> dn;
    if (k == n - 1)
    {
        for (int i = 0; i * 2 < n; !i?i++:i*=2)
        {
            cout << i << " " << n - 1 - 2 * i << "\n";
            dn.insert(i);
        }
        cout << n / 2 << " " << n - 2 << "\n";
        dn.insert(n / 2);
        dn.insert(n / 2 - 1);
    }
    else
    {
        cout << k << " " << n - 1 << "\n";
        if (k)
            cout << "0 " << n - k - 1 << "\n";
        dn.insert(min(k, n - k - 1));
        dn.insert(0);
    }
    for (int i = 1; i * 2 < n; i++)
        if (dn.find(i) == dn.end())
            cout << i << " " << n - i - 1 << "\n";
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