#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long tot = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            long long k;
            cin >> k;
            tot += k;
        }
    cout << fixed << setprecision(7) << tot / 2.0 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}