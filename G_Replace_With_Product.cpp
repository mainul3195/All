#include <bits/stdc++.h>
using namespace std;
#define lim 200000000000000LL
vector<long long> v, c_sum;
void solve()
{
    int n;
    cin >> n;
    v = c_sum = vector<long long>(n + 1, 0);
    vector<int> non_zero;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] > 1)
            non_zero.push_back(i);
        c_sum[i] = c_sum[i - 1] + v[i];
    }
    int l = 1, r = 1;
    long long mx = 0;
    for (int i = 0; i < non_zero.size(); i++)
    {
        long long mul = 1;
        for (int j = i; j < non_zero.size(); j++)
        {
            __int128_t tmp = (__int128_t)mul * v[non_zero[j]];
            if (tmp > lim)
            {
                cout << non_zero[0] << " " << non_zero.back() << "\n";
                return;
            }
            mul *= v[non_zero[j]];
            if (mul > c_sum[non_zero[j]] - c_sum[non_zero[i] - 1] && c_sum[non_zero[i] - 1] + mul + c_sum[n - 1] - c_sum[non_zero[j]] > mx)
            {
                mx = c_sum[non_zero[i] - 1] + mul + c_sum[n - 1] - c_sum[non_zero[j]];
                l = non_zero[i];
                r = non_zero[j];
            }
        }
    }
    cout << l << " " << r << "\n";
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