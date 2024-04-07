#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
void solve()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int w = k1 + k2;
    int b = n*2 - w;
    int gw, gb;
    cin >> gw >> gb;
    if(w/2 >= gw && b/2 >= gb)
        cout << "YES\n";
    else 
        cout << "NO\n";
    return ;

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