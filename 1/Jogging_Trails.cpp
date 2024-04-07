#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<set<int>>adj;
void solve()
{
    cin >> n >> m;
    adj = vector<set<int>>(n+1, set<int>());
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}