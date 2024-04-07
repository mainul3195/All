#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> v(26, 0);
    int tot = 0;
    for (auto i : s)
    {
        if (v[i - 'a'])
        {
            tot += 2;
            v = vector<int>(26, 0);
        }
        else
            v[i - 'a'] = 1;
    }
    cout << s.size() - tot << "\n";
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