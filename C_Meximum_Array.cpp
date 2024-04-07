#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), mex(n), ans;
    for (auto &i : v)
        cin >> i;
    set<int> num;
    for (int i = 0; i <= n; i++)
        num.insert(i);
    for (int i = n - 1; i >= 0; i--)
    {
        num.erase(v[i]);
        mex[i] = *num.begin();
    }
    // for (auto i : mex)
    //     cout << i << " ";
    // cout << "\n";
    for (auto i : v)
        num.insert(i);
    int prev, M;
    for (int i = 0; i < n; i++)
    {
        M = mex[i];
        prev = i;
        do
        {
            num.erase(v[i++]);
            // cout << *num.begin() << " ";
        } while (*num.begin() != M && i <= n);
        i--;
        ans.push_back(M);
        // cout << "\n" << i << "\n";
        for (int j = prev; j <= i; j++)
            num.insert(v[j]);
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
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