#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int n;
void solve()
{
    cin >> n;
    a = vector<long long>(n);
    for (auto &i : a)
        cin >> i;
    int taken = 0;
    long long sum = 0;
    multiset<long long> st;
    for (auto i : a)
    {
        if (sum + i >= 0)
        {
            st.insert(i);
            taken++;
            sum += i;
        }
        else
        {
            if (st.empty() || *(st.begin()) >= i)
                continue;
            sum += -*(st.begin()) + i;
            st.erase(st.begin());
            st.insert(i);
        }
    }
    cout << taken << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
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