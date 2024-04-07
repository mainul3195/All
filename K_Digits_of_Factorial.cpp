#include <bits/stdc++.h>
using namespace std;
vector<double> totlog(1000007);
void solve()
{
    long long n, b;
    cin >> n >> b;
    cout << (long long)(totlog[n]/log10(b) + .000000000000000001) + 1 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    totlog[0] = 0;
    for (int i = 1; i < 1000006; i++)
        totlog[i] = totlog[i - 1] + log10(i);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}