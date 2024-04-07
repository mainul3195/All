#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, c, d;
vector<int> reward, cum_sum;
int getsum(int x)
{
    if (x > n)
        x = n;
    return cum_sum[x];
}
bool possible(int k)
{
    // cout << k << " -> ";
    int times = d / (k + 1);
    int tot = times * getsum(k + 1);
    int remaining = d % (k + 1);
    // cout << tot << "\n";
    tot += getsum(remaining);
    // cout << tot << "\n";
    if (tot >= c)
        return 1;
    return 0;
}
void solve()
{
    cin >> n >> c >> d;
    reward = vector<int>(n);
    cum_sum = vector<int>(n + 1, 0);
    for (auto &i : reward)
        cin >> i;

    sort(reward.rbegin(), reward.rend());

    for (int i = 0; i < n; i++)
        cum_sum[i + 1] = cum_sum[i] + reward[i];
    if(d<n)
    {
        while(cum_sum.size()>d+1)
            cum_sum.pop_back();
        n=d;
    }
    if (getsum(d) >= c)
    {
        cout << "Infinity\n";
        return;
    }
    // for (auto i : cum_sum)
    //     cout << i << " ";
    // cout << "\n";
    int k = -1, l = 0, r = d, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (possible(mid))
        {
            k = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (k == -1)
        cout << "Impossible\n";
    else
        cout << k << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}