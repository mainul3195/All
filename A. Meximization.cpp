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
    int track[101]={0};
    vector<int> mn, dbl;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        if(track[j])
            dbl.push_back(j);
        else
        {
            mn.push_back(j);
            track[j]=1;
        }
    }
    sort(mn.begin(), mn.end());
    sort(dbl.begin(), dbl.end());
    for(int i=0;  i<mn.size(); i++)
        cout << mn[i] << " \n"[i==n-1];
    for(int i=0; i<dbl.size(); i++)
        cout << dbl[i] << " \n"[i==dbl.size()-1];
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