#include <bits/stdc++.h>
using namespace std;
int n;
int lg[200005];
vector<int> given, missing, ans;
set<int> st;
void solve()
{
    cin >> n;
    given = vector<int>(n / 2);
    missing.clear();
    st.clear();
    for (auto &i : given)
    {
        cin >> i;
        st.insert(i);
    }
    int m = -1;
    if (st.size() != n / 2)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if (st.find(i) == st.end())
            missing.push_back(i);
    ans.clear();
    st = set<int>(missing.begin(), missing.end());
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        ans.push_back(given[i]);
        auto it = st.upper_bound(given[i]);
        if (it == st.begin())
        {
            cout << "-1\n";
            return;
        }
        it--;
        ans.push_back(*it);
        st.erase(it);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[1] = 0;
    for (int i = 2; i <= 200004; i++)
        lg[i] = lg[i / 2] + 1;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}