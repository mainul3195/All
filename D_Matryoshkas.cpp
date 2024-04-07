#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // cout << x << " ";
        mp[x]++;
        st.insert(x);
    }
    int cnt = 0, prev = -3;
    vector<int> to_remove;
    // cout << "\nbefore: \n";
    // for (auto [a, b] : mp)
    //     cout << a << " -> " << b << "\n";
    while (st.size())
    {
        // cout << "here: ";
        // for (auto i : st)
        //     cout << i << " ";
        // cout << "\n";
        // for (auto [a, b] : mp)
        //     cout << a << " -> " << b << "\n";
        for (auto i : st)
        {
            if (i != prev + 1)
                cnt++;
            prev = i;
            mp[i]--;
            if (!mp[i])
                to_remove.push_back(i);
        }
        while (to_remove.size())
        {
            st.erase(to_remove.back());
            to_remove.pop_back();
        }
    }
    cout << cnt << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}