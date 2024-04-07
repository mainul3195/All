#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> tmp = v;
    sort(tmp.rbegin(), tmp.rend());
    int fmx = tmp[0], smx = tmp[1];
    for (auto i : v)
    {
        if (i == fmx)
            cout << i - smx << " ";
        else
            cout << i - fmx << " ";
    }
    cout << "\n";
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