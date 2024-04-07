#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long tot;
bool possible(int i = 0, long long taken = 0)
{
    if (i == v.size())
        return taken == tot / 2;
    return possible(i + 1, taken) || possible(i + 1, taken + v[i]);
}
void solve()
{
    string s;
    getline(cin, s);
    stringstream str(s);
    v.clear();
    int n;
    tot = 0;
    while (str >> n)
    {
        tot += n;
        v.push_back(n);
    }
    if (tot % 2 == 0 && possible())
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
    string s;
    getline(cin, s);
    while (t--)
        solve();
    return 0;
}