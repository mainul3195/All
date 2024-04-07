#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i <= s; i++)
        for (int j = 0; j <= s; j++)
            for (int k = 0; k <= s; k++)
                if (i + j + k <= s && i * j * k <= t)
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