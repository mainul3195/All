#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n), ans(n, INT_MAX);
    for (auto &i : v)
        cin >> i;
    ans[0] = 0;
    for (int i = 1; i < n; i++)
        for (int j = max(i - k, 0); j < i; j++)
            ans[i] = min(ans[i], ans[j] + abs(v[i] - v[j]));
    cout << ans[n - 1] << "\n";
    return 0;
}