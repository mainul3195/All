#include<bits/stdc++.h>
using namespace std;
struct nd
{
    int val, ind;
    bool operator < (const nd &a) const
    {
        return (val<a.val || (val == a.val && ind < a.ind));
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<nd>v;
        for(int i=0; i<n; i++)
        {
            int j;
            cin >> j;
            v.push_back({j, i});
        }
        sort(v.begin(), v.end());
        int tmp = 1;
        for(int i=0; i+1<n; i++)
            if(v[i+1].ind != v[i].ind+1)
                tmp++;
        if(tmp <= k)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}