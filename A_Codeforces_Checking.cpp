#include <bits/stdc++.h>
using namespace std;
set<char> st;
void solve()
{
    char c;
    cin >> c;
    if (st.find(c) != st.end())
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "codeforces";
    for (auto c : s)
        st.insert(c);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}