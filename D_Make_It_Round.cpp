#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    long long n, m;
    cin >> n >> m;
    long long tn = n, tm = m;
    long long n2 = 0, n5 = 0, m2 = 0, m5 = 0;
    while (n % 5 == 0)
    {
        n /= 5;
        n5++;
    }
    while (n % 2 == 0)
    {
        n /= 2;
        n2++;
    }
    while (m % 5 == 0)
    {
        m /= 5;
        m5++;
    }
    while (m % 2 == 0)
    {
        m /= 2;
        m2++;
    }
    // if ((!(n2 + n5) && tm < 10) || (n5 && tm < 2) || (n2 && tm < 5))
    // {
    //     cout << tm * tn << "\n";
    //     return;
    // }
    long long taken5 = 0, mul = 1;
    int mx = -1, ans5 = 0, ans2 = 0;
    while (mul <= tm)
    {
        m = tm / mul;
        // if (tm == 43)
        //     cout << m << " -> ";
        int tot2 = 0;
        while (m >= 2)
        {
            tot2++;
            m /= 2;
        }
        // if (tm == 43)
        // {
        //     cout << " -> " << mul << " " << tot2 << "\n";
        // }
        int tmpmx = min(n5 + taken5, n2 + tot2);
        if (tmpmx > mx)
        {
            ans5 = taken5, ans2 = tot2;
            mx = tmpmx;
        }
        mul *= 5;
        taken5++;
    }
    // cout << ans5 << " " << ans2 << "\n";
    int tot5 = n5 + ans5;
    int tot2 = n2 + ans2;
    if (tot5 < tot2)
        ans2 -= min(ans2, tot2 - tot5);
    else if (tot2 > tot5)
        ans5 -= min(ans5, tot5 - tot2);
    long long ml = ((long long)(pow(5, ans5) + .5)) * ((long long)(pow(2, ans2) + .5));
    cout << tn * ml * (tm / ml) << "\n";
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