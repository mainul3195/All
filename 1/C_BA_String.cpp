#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<long long> pos;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        while (i < n && s[i++] == '*')
            count++;
        i--;
        if (count)
            pos.push_back(count);
    }
    vector<int> ans(pos.size(), 0);
    for (auto &i : pos)
        i = i * k + 1;
    x--;
    for (int i = pos.size() - 1; x && i >= 0; i--)
    {
        ans[i] = x % pos[i];
        x /= pos[i];
    }
    // for (auto i : ans)
    //     cout << i << " ";
    // cout << "\n";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            int j = ans.back();
            ans.pop_back();
            while (j--)
                cout << "b";
            while (i < s.size() && s[i] == '*')
                i++;
            i--;
        }
        else
            cout << "a";
    }
    cout << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/