#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int e = 1, ans = 1;
    while (e < n)
    {
        int cnt = 1;
        while (e < n && v[e] <= v[e - 1] * 2)
            cnt++, e++;
        e++;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}