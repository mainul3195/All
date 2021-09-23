#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
long long powr(int n)
{
    long long ans = 1;
    while(--n)
        ans *= 10;
    return ans;
}
void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << powr(a) << " " << powr(b)+powr(c) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}