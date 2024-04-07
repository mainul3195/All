#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int okdone(int s, int e)
{
    int mxind = max_element(v.begin()+s, v.begin()+e+1) - v.begin();
    if (mxind == s || mxind == e)
        return 1;
    return 1 + min(okdone(s, mxind - 1), okdone(mxind + 1, e));
}

void solve()
{
    int n;
    cin >> n;
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    cout << okdone(0, n - 1) << "\n";
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