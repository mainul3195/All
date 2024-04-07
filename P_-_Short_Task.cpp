#include <bits/stdc++.h>
using namespace std;
long long sod[10000001], ans[10000001];
void pre_cal()
{
    for (int i = 1; i <= 10000000; i++)
        for (int j = i; j <= 10000000; j += i)
            sod[j] += i;
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= 10000000; i++)
        if (sod[i] <= 10000000 && ans[sod[i]] == -1)
            ans[sod[i]] = i;
    return;
}
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre_cal();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}