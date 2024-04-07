#include <bits/stdc++.h>
using namespace std;
long long f[200005], b[200005], mn[200005], taken[200005];
struct nd
{
    long long val;
    int ind, dir;
    bool operator<(const nd &a) const
    {
        return val < a.val || (val == a.val && dir > a.dir);
    }
};
void solve()
{
    long long n, c;
    cin >> n >> c;
    memset(taken, 0, sizeof(long long) * (n + 3));
    long long sum = 0;
    vector<nd> v;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        f[i] = x + i;
        b[i] = x + n - i + 1;
        mn[i] = min(f[i], b[i]);
        v.push_back({mn[i], i, mn[i] == f[i]});
    }
    sort(v.begin(), v.end());
    int cur_ans = 0, found = 0;
    vector<long long> c_sum;
    c_sum.push_back(0);
    for (int i = 0; i < n; i++)
        if (!taken[v[i].ind])
        {
            sum += v[i].val;
            c_sum.push_back(sum);
            if (sum > c)
            {
                sum -= v[i].val;
                break;
            }
            taken[v[i].ind] = 1;
            if (v[i].dir)
                found = 1;
            cur_ans++;
        }
    if (found)
    {
        cout << cur_ans << "\n";
        return;
    }
    map<int, int> pos;
    for (int ind = 0; ind <= cur_ans; ind++)
        pos[v[ind].ind] = ind + 1;
    // cout << cur_ans << " " << sum  << "\n";
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    //     cout << b[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    //     cout << mn[i] << " ";
    // cout << "\n";
    // for(auto i: c_sum)
    //     cout << i << " ";
    //     cout << "\n";
    int minant = cur_ans;
    for (int i = 1; i <= n; i++)
        if (f[i] <= c)
        {
            long long less = f[i] - (c - sum);
            if (taken[i])
                less -= b[i];
            // cout << i << " -> " << less << "\n";
            if (less <= 0)
            {
                cout << cur_ans << "\n";
                return;
            }
            int l = 1, r = cur_ans, mid, ans = -1;
            while (l <= r)
            {
                mid = (l + r) / 2;
                long long cum_s = c_sum[cur_ans] - c_sum[mid - 1];
                if (taken[i] && pos[i] >= mid)
                    cum_s -= mn[i];
                if (cum_s >= less)
                {
                    ans = cur_ans - mid + 1;
                    if (taken[i] && pos[i] >= mid)
                        ans--;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            if (!taken[i])
                ans--;
            // cout << ans << " here " << minant <<  "\n";
            minant = min(minant, ans);
            // cur_ans = max(cur_ans, cur_ans - ans - (taken[i] == 1) + 1);
        }
    // cout << minant << "\n";
    cout << cur_ans - minant << "\n";
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