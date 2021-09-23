#include<bits/stdc++.h>
using namespace std;
vector<int> track(4000010);
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        fill(track.begin(), track.begin()+n+m+5, 0);
        for(int i=2; i<n+2; i++)
            track[i]++, track[i+m]--;
        for(int i=3; i<=n+m+2; i++)
            track[i]+=track[i-1];
        long long ans=0;
        for(int i=2; i<=n+m; i++)
            if(track[i]&1)
            {
                ans ^= (i+k);
            }
        cout << ans << "\n";
    }
    return 0;
}