#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string pre = s;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            char prev = s[i - 1];
            char next = s[(i + 1) % s.size()];
            set<char> st;
            st.insert('R');
            st.insert('p');
            st.insert('s');
            st.erase(prev);
            if (st.lower_bound(next) != st.end())
                st.erase(next);
            s[i] = *st.begin();
            ans1++;
            i++;
        }
    }
    if (s[0] == s.back())
        ans1++;
    s = pre;
    char c = s.back();
    for (int i = s.size() - 1; i; i--)
        s[i] = s[i - 1];
    s[0] = c;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            char prev = s[i - 1];
            char next = s[(i + 1) % s.size()];
            set<char> st;
            st.insert('R');
            st.insert('p');
            st.insert('s');
            st.erase(prev);
            if (st.lower_bound(next) != st.end())
                st.erase(next);
            s[i] = *st.begin();
            ans2++;
            i++;
        }
    }
    if (s[0] == s.back())
        ans2++;
    cout << min(ans1, ans2) << "\n";
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