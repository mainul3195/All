#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> v(n);
    long long tot = 0;
    for (auto &i : v)
        cin >> i;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            last = i;
        else
        {
            if (last == -1)
                tot += v[i];
            else if (v[last] > v[i])
            {
                tot += v[last];
                last = i;
            }
            else
                tot += v[i];
        }
    }
    cout << tot << "\n";
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