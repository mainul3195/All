#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
void solve()
{
    cin >> n >> m;
    vector<long long> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        v[i] += v[i - 1];
    // for (auto i : v)
    //     cout << i << " ";
    cout << "\n";
    while (m--)
    {
        cin >> q;
        int ind = lower_bound(v.begin(), v.end(), q) - v.begin();
        cout << ind << " " << q - v[ind - 1] << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}