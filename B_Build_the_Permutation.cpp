#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b + 2 > n || abs(a - b) > 1)
        cout << "-1\n";
    else
    {
        vector<int> ans(n, 0);
        if (a >= b)
        {
            int done = 0;
            for (int i = 1; done < a; i += 2, done++)
                ans[i] = n--;
            int s = 1;
            for (auto &i : ans)
                if (!i)
                    i = s++;
            for (auto i : ans)
                cout << i << " ";
            cout << "\n";
        }
        else
        {
            int s = 1, done = 0;
            for (int i = 1; done < b; i += 2, done++)
                ans[i] = s++;
            for (auto &i : ans)
                if (!i)
                    i = s++;
            for (auto i : ans)
                cout << i << " ";
            cout << "\n";
        }
    }

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