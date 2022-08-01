#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i++)
        a[i] = a[0] - a[i];
    long long gcd = 0;
    for (int i = 1; i < n; i++)
        gcd = __gcd(gcd, a[i]);
    for (auto i : b)
        cout << __gcd(a[0] + i, gcd) << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}