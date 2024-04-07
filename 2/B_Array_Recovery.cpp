#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    int nm;
    cin >> nm;
    ans.push_back(nm);
    bool multiple = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> nm;
        if (ans.back() - nm >= 0 && nm)
            multiple = 1;
        ans.push_back(ans.back() + nm);
    }
    if (multiple)
        cout << "-1\n";
    else
    {
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
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