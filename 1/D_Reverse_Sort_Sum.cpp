#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n), ans(n), tmp(n, 0);
    long long tot = 0;
    for (auto &i : c)
    {
        cin >> i;
        tot += i;
    }
    int no_of_ones = tot / n;
    // cout << no_of_ones << "\n";
    int minant = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (no_of_ones <= i)
        {
            tmp[i - no_of_ones]++;
            // cout << "\t " << i - no_of_ones << " " << tmp[i - no_of_ones] << " ";
            // cout << "\n";
        }
        // cout << i << " -> ";
        minant -= tmp[i];
        // cout << minant << " ";
        int sm = c[i] - minant;
        // cout << c[i] << " " << sm << " ";
        if (no_of_ones && sm == i + 1)
        {
            ans[i] = 1;
            no_of_ones--;
        }
        else
            ans[i] = 0;

        minant++;
        // cout << "\n";
    }
    for (auto i : ans)
        cout << i << " ";
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