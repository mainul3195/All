#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    int l = 1, r = n, mid, ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        cout << "? " << mid << " ";
        for (int i = 1; i <= mid; i++)
            cout << i << " \n"[i == mid];
        long long sum;
        cin >> sum;
        if (sum > v[mid - 1])
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << "! " << ans << "\n";
    return;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}