#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
map<long long, int> mp;
void solve()
{
    int n, k;
    cin >> n >> k;
    v = vector<long long>(n);
    int count = 0;
    for (auto &i : v)
    {
        cin >> i;
        mp[i] = ++count;
    }
    while (k--)
    {
        long long val;
        cin >> val;
        auto it = lower_bound(v.begin(), v.end(), val);
        if (it == v.begin() && *it > val)
            cout << val << "\n";
        else
        {
            unsigned long long l = 1, r = 1000000000100000000, mid, ans;
            while (l <= r)
            {
                mid = (l + r) / 2;
                auto it = lower_bound(v.begin(), v.end(), mid);
                long long avail = mid;
                if (it == v.begin() && *it > mid)
                    avail -= 0;
                else if (*it == mid)
                    avail -= mp[mid];
                else
                    avail -= mp[*(--it)];
                if (avail == val)
                {
                    ans = mid;
                    r = mid - 1;
                }
                if (avail < val)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            cout << ans << "\n";
        }
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