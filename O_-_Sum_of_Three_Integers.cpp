#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, s;
    cin >> k >> s;
    int ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            if ((s - i - j) >= 0 && s - i - j <= k)
                ans++;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}