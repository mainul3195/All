#include <bits/stdc++.h>
using namespace std;
int n, m;
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}
void solve()
{
    cin >> n >> m;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = '9'; i > '0'; i--)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                if (v[j][k] == i)
                {
                    v[j][k] = i - 1;
                    if (valid(j - 1, k))
                        v[j - 1][k] = max((int)v[j - 1][k], i - 1);
                    if (valid(j, k - 1))
                        v[j][k - 1] = max((int)v[j][k - 1], i - 1);
                    if (valid(j + 1, k))
                        v[j + 1][k] = max((int)v[j + 1][k], i - 1);
                    if (valid(j, k + 1))
                        v[j][k + 1] = max((int)v[j][k + 1], i - 1);
                }
    for (auto s : v)
    {
        for (auto c : s)
            cout << (c == '#' ? '#' : '.');
        cout << "\n";
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}