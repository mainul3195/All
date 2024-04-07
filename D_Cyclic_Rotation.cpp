#include <bits/stdc++.h>
using namespace std;
vector<int> a, c;
int n;
int Next(int j)
{
    j++;
    for (; j < n; j++)
        if (c[j] != -1)
            return j;
    return j;
}
bool possible()
{
    cin >> n;
    a = vector<int>(n);
    c = vector<int>(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : c)
        cin >> i;
    map<int, vector<int>> mp;
    for (int i = 0; i < n - 1; i++)
        if (c[i] == c[i + 1])
            mp[c[i]].push_back(i);
    for (auto &[i, v] : mp)
        reverse(v.begin(), v.end());
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (a[i] == c[j])
            i++, j = Next(j);
        else
        {
            if (!mp[a[i]].size())
                return 0;
            int ind;
            do
            {
                ind = mp[a[i]].back();
                mp[a[i]].pop_back();
            } while (ind < j && mp[a[i]].size());
            if (ind < j)
                return 0;
            c[ind] = -1;
            i++;
        }
    }
    if (i == n && j == n)
        return 1;
    return 0;
}
void solve()
{
    if (possible())
        cout << "YES\n";
    else
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