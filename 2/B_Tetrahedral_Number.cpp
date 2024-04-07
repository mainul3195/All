#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= 21; i++)
        for (int j = 0; j <= 21; j++)
            for (int k = 0; k <= 21; k++)
                if (i + j + k <= n)
                    cout << i << " " << j << " " << k << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}