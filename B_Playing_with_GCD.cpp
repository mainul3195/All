#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    bool ok = 1;
    vector<int> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        ans.push_back(lcm(v[i], v[i - 1]));
        if (__gcd(ans[i], ans[i - 1]) != v[i - 1])
        {
            ok = !ok;
            break;
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}