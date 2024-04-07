#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int tot_sum = s;
    for (auto i : v)
        tot_sum += i;
    tot_sum <<= 1;
    int last = 1;
    bool found = 0;
    while (last * last + last <= tot_sum)
    {
        if (last * last + last == tot_sum)
        {
            found = 1;
            break;
        }
        last++;
    }
    if (found)
    {
        for (auto i : v)
            if (i > last)
            {
                cout << "NO\n";
                return;
            }
        set<int> st(v.begin(), v.end());
        if (st.size() != v.size())
        {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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