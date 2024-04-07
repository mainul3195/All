#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    n--;
    vector<int> v;
    while (n)
    {
        v.push_back((n % 5) * 2);
        n /= 5;
    }
    if (v.empty())
        cout << 0 << "\n";
    else
    {
        reverse(v.begin(), v.end());
        for (auto i : v)
            cout << i;
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