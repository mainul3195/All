#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
vector<int> track(100005);
void solve()
{
    int n, m;
    cin >> n >> m;
    fill(track.begin(), track.begin()+m+1,0);

    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        track[j%m]++;
    }
    int ans=0;
    if(track[0])
        ans=1;
    for(int i=1, j=m-1; i<=j; i++, j--)
    {
        if(i==j && track[i])
            ans++;
        else
        {
            int tm =  abs(track[i]-track[j]);
            if(!tm && track[i])
                ans++;
            else    
                ans += tm;
        }
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