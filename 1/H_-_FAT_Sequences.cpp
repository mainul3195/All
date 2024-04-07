#include <bits/stdc++.h>
using namespace std;
vector<long long> ans(100005);
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
    int t;
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= 100003; i++)
        ans[i] = (ans[i - 1] + ans[i - 2] + 1) % 1000000007;
    cin >> t;
    while (t--)
        solve();
    return 0;
}