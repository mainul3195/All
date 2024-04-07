#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k > 1 && n & 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (start > n * k)
                start = 2;
            cout << start << " ";
            start += 2;
        }
        cout << "\n";
    }
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