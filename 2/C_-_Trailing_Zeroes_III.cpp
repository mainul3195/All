#include <bits/stdc++.h>
using namespace std;
int lastZeroes(int n)
{
    int ans = 0;
    while (n)
    {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    int l = 5, r = 400000100, mid, ans = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int tmp = lastZeroes(mid);
        if (tmp < n)
            l = mid + 1;
        else
        {
            r = mid - 1;
            tmp == n ? ans = mid : 0;
        }
    }
    if (ans == -1)
        cout << "impossible\n";
    else
        cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}