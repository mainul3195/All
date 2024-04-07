#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> a;
    set<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        int nm = v[i];
        while (i < v.size() && v[i] == nm)
            i++;
        i--;
        a.push_back(nm);
        st.insert(nm);
    }
    if (st.size() != a.size())
        cout << "IMPOSSIBLE\n";
    else
    {
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}