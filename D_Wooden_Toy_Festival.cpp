#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
bool possible(long long val)
{
    long long jmp = 2 * val;
    int count = 0;
    int start = 0;
    while (start < n)
    {
        int ind = upper_bound(v.begin(), v.end(), v[start]+jmp)-v.begin();
        start = ind;
        count++;
        if(count>3)
            break;
    }
    return count<=3;
}
void solve()
{
    cin >> n;
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long l = 0, r = 1000000000, mid, ans = 1000000000;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (possible(mid))
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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}