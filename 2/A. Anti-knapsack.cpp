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
    int n, k;
    cin >> n >> k;
    int  lim = (k+1)/2;
    cout << n-lim << "\n";
    for(int i=lim; i<k; i++)
        cout << i << " \n"[i==n];
    for(int i=k+1; i<=n; i++)
        cout << i << " \n"[i==n];
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