#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int>v(m);
    int mn = 1000000, mx = -1000000;
    for(auto &i: v)
    {
        cin >> i;
        mn = min(mn, i);
        mx = max(mx, i);
    }
    if(n>=m)
    {
        cout << "0\n";
        return 0;
    }
    sort(v.begin(), v.end());
    vector<int> dif;
    for(int i=1; i<m; i++)
        dif.push_back(v[i]-v[i-1]);
    sort(dif.begin(), dif.end(), greater<int>());
    int gap = 0;
    for(int i=0; i<n-1; i++)
        gap+=dif[i];
    cout << mx - mn - gap << "\n";
    return 0;
}