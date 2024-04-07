#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> v;
bool ok(long long w)
{
    for (auto i : v)
        if (i > w)
            return 0;
    long long line_count = 0;
    long long cur_len = 0;
    for (auto i : v)
    {
        if (cur_len == 0)
        {
            cur_len += i;
            // if (w == 9)
            //     cout << "Here\n";
            line_count++;
        }
        else
        {
            if (cur_len + 1 + i <= w)
                cur_len += 1 + i;
            else
            {
                // if (w == 9)
                //     cout << "here\n";
                line_count++;
                cur_len = i;
            }
        }
        if (cur_len == w)
            cur_len = 0;
    }
    // if (w == 9)
    //     cout << w << " -> " << line_count << "\n";
    return line_count <= m;
}
void solve()
{
    cin >> n >> m;
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    long long l = 0, r = 10000000000000000LL, mid, ans = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}