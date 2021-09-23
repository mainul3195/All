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
    ll n, k;
    cin >> n >> k;
    vci v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    bool ok=1;
    int pos=-1;
    ll tot=0;
    while(ok)
    {
        // for(int i=0; i<n; i++)
        //     cout << v[i] << " \n"[i==n-1];
        ok=0;
        for(int i=1; i<n; i++)
        {
            if(v[i]>v[i-1])
            {
                tot++;
                v[i-1]++;
                if(tot>=k)
                {
                    pos = i;
                    break;
                }
                ok=1;
                break;
            }
        }
    }
    cout << pos << "\n";
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