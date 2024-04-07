#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> ones;
    for (int i = n - 1; i >= 0; i--)
        if (v[i])
            ones.push_back(i);
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!ones.size() || ones.back() > i)
            break;
        if (!v[i])
        {
            ones.pop_back();
            c++;
        }
    }
    cout << c << "\n";
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