#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int mn = *min_element(v.begin(), v.end());
    for (auto i : v)
        if (i % mn)
        {
            cout << "1\n";
            return;
        }
    cout << (count(v.begin(), v.end(), mn) + 1) / 2 << "\n";
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