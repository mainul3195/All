#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n), ans(n, 0);
    for (auto &i : v)
        cin >> i;
    ans[0] = 0;
    ans[1] = abs(v[0] - v[1]);
    for (int i = 2; i < n; i++)
        ans[i] = min(ans[i - 1] + abs(v[i - 1] - v[i]), ans[i - 2] + abs(v[i - 2] - v[i]));
    cout << ans[n - 1] << "\n";
    return 0;
}