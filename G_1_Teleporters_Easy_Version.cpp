#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<long long>v(n);
    for(auto &i: v)
        cin >> i;
    for(int i = 1; i<=n; i++)
        v[i-1]+=i;
    sort(v.begin(), v.end());
    int sum = 0, i;
    for(i = 0; i<n; i++)
    {
        sum += v[i];
        if(sum>c)
            break;
    }
    cout << i << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}