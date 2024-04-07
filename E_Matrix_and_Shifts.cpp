#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    int tot1 = 0, tot0 = 0;
    for (auto s : v)
        for (auto c : s)
        {
            if (c == '0')
                tot0++;
            else
                tot1++;
        }
    int mn = 1000000000;
    for (int i = 0; i < n; i++)
    {
        int r = 0, c = i, zeroes = 0;
        for (int j = 0; j < n; j++, r = (r + 1) % n, c = (c + 1) % n)
            if (v[r][c] == '0')
                zeroes++;
        int ones = n - zeroes;
        mn = min(zeroes + tot1 - ones, mn);
    }
    cout << mn << "\n";
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