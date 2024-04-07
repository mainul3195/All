#include <bits/stdc++.h>
using namespace std;
//complexity O(nloglogn)
#define lim 5000002
vector<unsigned long long> phi(lim + 1);
void calc_phi()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i < lim; i++)
        phi[i] = i;
    for (int i = 2; i < lim; i++)
        if (phi[i] == i)
            for (int j = i; j < lim; j += i)
                phi[j] -= phi[j] / i;
    return;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    cout << phi[b] - phi[a - 1] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calc_phi();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}