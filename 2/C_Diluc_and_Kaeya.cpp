#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d = 0, k = 0;
    map<pair<int, int>, int> mp;
    for (auto i : s)
    {
        i == 'K' ? k++ : d++;
        int g = __gcd(d, k);
        cout << ++mp[{d / g, k / g}] << " ";
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