#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> dig(n);
    for (auto &i : dig)
        cin >> i;
    set<int> st;
    for (auto i : dig)
        st.insert(i);
    if (st.size() == k)
    {
        cout << "0\n";
        return;
    }
    int after_missing = -1;
    vector<int> before_missing;
    for (int i = dig[n - 1] - 1; i >= 0 && dig[n - 1] - i <= 106; i--)
        if (st.find(i) == st.end())
            before_missing.push_back(i);
    reverse(before_missing.begin(), before_missing.end());
    for (int i = k - 1; i > dig[n - 1] && k - i <= 106; i--)
        if (st.find(i) == st.end())
        {
            after_missing = i;
            break;
        }
    // cout << "Before missing: ";
    // for (auto i : before_missing)
    //     cout << i << " ";
    // cout << "\n";
    // cout << "After missing: " << after_missing << "\n";
    if (before_missing.empty())
        cout << after_missing - dig[n - 1] << "\n";
    else
    {
        int frst_non_last = n - 2;
        for (; frst_non_last >= 0; frst_non_last--)
            if (dig[frst_non_last] != k - 1)
                break;
        int d1 = 0, d2;
        if (frst_non_last == -1)
            d2 = 1;
        else
            d2 = dig[frst_non_last] + 1;
        auto it = find(before_missing.begin(), before_missing.end(), d1);
        if (it != before_missing.end())
            before_missing.erase(it);
        it = find(before_missing.begin(), before_missing.end(), d2);
        if (it != before_missing.end())
            before_missing.erase(it);
        if (before_missing.empty())
            cout << k - dig[n - 1] << "\n";
        else
            cout << before_missing.back() + k - dig[n - 1] << "\n";
    }
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