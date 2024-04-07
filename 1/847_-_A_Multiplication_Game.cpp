#include <bits/stdc++.h>
using namespace std;
long long n;
map<long long, bool> dp;
bool okdone(long long i = 1)
{
    if (i >= n)
        return 1;
    if (dp.count(i))
        return dp[i];
    bool ok = 0;
    for (int ml = 2; ml <= 9; ml++)
        ok |= okdone(i * ml);
    return dp[i] = !ok;
}
void solve()
{
    while (cin >> n)
    {
        dp.clear();
        if (!okdone())
            cout << "Stan wins.\n";
        else
            cout << "Ollie wins.\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}