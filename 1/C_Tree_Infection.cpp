#include <bits/stdc++.h>
using namespace std;
int n;
vector<map<int, int>::iterator> v;
vector<int> child;
void solve()
{
    cin >> n;
    child = vector<int>(n, 0);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        child[p - 1]++;
    }
    sort(child.rbegin(), child.rend());
    while (child.back() == 0)
        child.pop_back();
    child.push_back(1);
    n = child.size();
    int ans = n;
    for (int i = 0; i < n; i++)
        child[i] = max(0, child[i] - n + i);
    sort(child.rbegin(), child.rend());
    while (child.back() == 0)
        child.pop_back();
    while (child.size())
    {
        ans++;
        n = child.size();
        for (auto &i : child)
            i--;
        if(child[0])
            child[0]--;
        sort(child.rbegin(), child.rend());
        while (child.size() && child.back() == 0)
            child.pop_back();
    }
    cout << ans << "\n";
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