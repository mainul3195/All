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
    ll a, b, n;
    cin >> a >> b >> n;
    vector<pll> mons(n);
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        mons[i].first = j;
    }
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        mons[i].second = j;
    }
    sort(mons.begin(), mons.end());
    bool ok=1;
    for(int i=0; i<n; i++)
    {
        ll avail_attack = (b+mons[i].first-1)/mons[i].first;
        ll needed_attack = (mons[i].second+a-1)/a;
        if(avail_attack < needed_attack)
        {
            ok=0;
            break;
        }
        b -= (ll)needed_attack*mons[i].first;
    }
    if(ok)
        cout << "YES\n";
    else 
        cout << "NO\n";
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