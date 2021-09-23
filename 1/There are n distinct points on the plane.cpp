#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        vector<pair<int, int> > mid;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                mid.push_back({v[i].first+v[j].first, v[i].second+v[j].second});
        sort(mid.begin(), mid.end());
        long long ans=0;
        long long same=0;
        for(int i=1; i<mid.size(); i++)
        {
            if(mid[i].first == mid[i-1].first && mid[i].second == mid[i-1].second)
                same ++;
            else
            {
                ans += same*(same+1)/2;
                same=0;
            }
        }
        ans += same*(same+1)/2;
        cout << "Case " << ++tc << ": " << ans << "\n";
    }
    return 0;
}