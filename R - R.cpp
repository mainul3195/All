#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        v.push_back({j, i});
    }
    sort(v.begin(), v.end());
    int i=0;
    int mn=10000000;
    while(++i<n && v[i].first==v[i-1].first)
        mn=min(mn, v[i].second-v[i-1].second);
    cout << mn << "\n";
    return 0;
}