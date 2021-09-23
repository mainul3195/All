#include<bits/stdc++.h>
using namespace std;
int n, c, k;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c >> k;
    vector<int> t(n);
    for(auto &i: t)
        cin >> i;
    sort(t.begin(), t.end());
    int ans = 0;
    int count = 0;
    int last = t[0];
    int cango = 0;
    for(int i=0; i<n; i)
    {
        ans ++;
        count = 0;
        int first = t[i],j;
        for(j=i; j<n && t[j]-first <= k && count < c; j++, count ++);
        i = j;
    }
    cout << ans << "\n";
    return 0;
}