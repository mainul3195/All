#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> num;
    int pre, cur, frst;
    cin >> pre;
    frst = pre;
    if (k == 1)
    {
        cout << "Yes\n";
        return;
    }
    for (int i = 1; i < k; i++)
    {
        cin >> cur;
        num.push_back(cur - pre);
        pre = cur;
    }
    vector<int> tmp = num;
    sort(tmp.begin(), tmp.end());
    if (num != tmp)
    {
        cout << "No\n";
        return;
    }
    int t = frst - (n - k) * num[0];
    // cout << t << " " << frst << " " << n << " " << k << " " << n - k << " " << num[0] << "\n";
    if (t <= num[0])
        cout << "Yes\n";
    else
        cout << "No\n";
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