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
    int n , q;
    cin >> n >> q;
    vector<int> pos(51, 0);
    for(int i=1; i<=n; i++)
    {
        int j;
        cin >> j;
        if(!pos[j])
            pos[j] = i;
    }
    for(int i=0; i<q; i++)
    {
        int j;
        cin >> j;
        cout << pos[j] << " \n"[i==q-1];
        if(i==q-1)
            return;
        for(int l=1; l<=50; l++)
            if(pos[l]>0 && pos[l]<pos[j])
                pos[l]++;
        pos[j]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}