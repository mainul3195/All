#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int ind, val;
    bool operator<(const nd &a) const
    {
        return val < a.val || (val == a.val && ind > a.ind);
    }
};
vector<nd> v;
void solve()
{
    int n;
    cin >> n;
    cout << v[n].ind << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    v = vector<nd>(1001);
    int i = 0;
    for (auto &[ind, val] : v)
        ind = i++, val = 1;
    v[0].val = 0;
    for (int i = 2; i <= 1000; i++)
        for (int j = i; j <= 1000; j += i)
            v[j].val++;

    sort(v.begin(), v.end());
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}