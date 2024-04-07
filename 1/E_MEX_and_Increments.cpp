#include <bits/stdc++.h>
using namespace std;
vector<long long> cost, ans;
void solve()
{
    int n;
    cin >> n;
    cost = vector<long long>(n + 2, 0);
    ans = vector<long long>(n + 1, 0);
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        count[j]++;
    }
    multiset<int> st;
    bool ok = 1;
    for (int i = 0; i <= n; i++)
    {
        if (!ok)
        {
            ans[i] = -1;
            continue;
        }
        if (i == 0)
            ans[i] = count[0];
        else if (i == 1)
        {
            if (st.empty())
            {
                ok = 0;
                ans[i] = -1;
                continue;
            }
            else
            {
                st.erase(st.begin());
                ans[1] = count[1];
                cost[0] = 0;
            }
        }
        else
        {
            if (st.empty())
            {
                ok = 0;
                ans[i] = -1;
                continue;
            }
            auto it = st.end();
            it--;
            // cout << i << " -> " << *it << "\n";
            cost[i - 1] = cost[i - 2] + i - 1 - *it;
            st.erase(it);
            ans[i] = cost[i - 1] + count[i];
        }
        while (count[i]--)
            st.insert(i);
    }
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
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