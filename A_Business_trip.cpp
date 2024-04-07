#include<bits/stdc++.h>
using namespace std;
int k;
vector<int> v(12);
void solve()
{
    cin >> k;
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    int tot = 0, ans = 0;
    for(int i = 11;tot<k && i>=0; i--)
    {
        ans ++;
        tot += v[i];
    }
    cout << (tot<k?-1:ans) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve(); 
    return 0;
}