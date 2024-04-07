#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<int>c;
vector<pair<int, int>>ranges;
void solve()
{
    cin >> n >> q;
    c = vector<int>(n);
    ranges = vector<pair<int, int>>(q);
    for(auto &i: c)
        cin >> i;
    for(auto &[a, b]: ranges)
        cin >> a >> b;
    
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}