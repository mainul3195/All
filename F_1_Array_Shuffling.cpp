#include <bits/stdc++.h>
using namespace std;
struct pr
{
    int val, ind;
    bool operator<(const pr &a) const
    {
        return val < a.val || (val == a.val && ind < a.ind);
    }
};
ostream &operator<<(ostream &os, pr p)
{
    return os << "(" << p.val << "," << p.ind << ")";
}
vector<int> NoO;
vector<pr> v;
bool cmp(pr a, pr b)
{
    return NoO[a.val] < NoO[b.val] || (NoO[a.val] == NoO[b.val] && a.val < b.val);
}
void solve()
{
    int n, c = 0;
    cin >> n;
    v = vector<pr>(n);
    NoO = vector<int>(n + 1, 0);
    vector<int> mn;
    for (auto &i : v)
    {
        cin >> i.val;
        mn.push_back(i.val);
        NoO[i.val]++;
        i.ind = c++;
    }
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    vector<int> sorted_index, changed_index(n);
    sort(v.begin(), v.end(), cmp);
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    for (auto [vl, i] : v)
        sorted_index.push_back(i);
    for (int i = NoO[v[n - 1].val], j = 0; i < n; i++, j++)
        changed_index[sorted_index[j]] = sorted_index[i];
    for (int i = n - NoO[v[n - 1].val], j = 0; i < n; i++, j++)
        changed_index[sorted_index[i]] = sorted_index[j];
    for (int i = 0; i < n; i++)
        cout << mn[changed_index[i]] << " \n"[i == n - 1];
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