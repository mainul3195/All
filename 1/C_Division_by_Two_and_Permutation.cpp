#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<bool> done(n + 1, 0);
    vector<int> num(n);
    for (auto &i : num)
        cin >> i;
    sort(num.rbegin(), num.rend());
    bool ok = 1;
    for (auto i : num)
    {
        while (i > n || done[i])
            i /= 2;
        if (!i)
        {
            ok = 0;
            break;
        }
        done[i] = 1;
    }
    done[0] = 1;
    for (auto i : done)
        if (!i)
        {
            ok = 0;
            break;
        }
    cout << (ok ? "YES" : "NO") << "\n";
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