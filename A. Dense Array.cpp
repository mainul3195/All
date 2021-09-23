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
    int n;
    cin >> n;
    int prev;
    cin >> prev;
    int nw;
    int ans=0;
    for(int i=1; i<n; i++)
    {
        cin >> nw;
        int a=max(prev, nw), b= min(prev, nw);
        while(2*b <a)
        {
            ans++;
            b<<=1;
        }
        prev = nw;
    }
    cout << ans << "\n";
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