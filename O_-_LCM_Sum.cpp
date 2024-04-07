#include <bits/stdc++.h>
using namespace std;
long long phi[1000006], tmp[1000006];
void make_phi()
{
    for (int i = 0; i <= 1000000; i++)
        phi[i] = i;
    for (int i = 2; i <= 1000000; i++)
        if (phi[i] == i)
            for (int j = i; j <= 1000000; j += i)
                phi[j] -= phi[j] / i;
    for (int i = 1; i <= 1000000; i++)
        for (int j = i; j <= 1000000; j += i)
            tmp[j] += phi[i] * i;
    return;
}
void solve()
{
    int n;
    cin >> n;
    cout << n * (tmp[n] + 1) / 2 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_phi();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}