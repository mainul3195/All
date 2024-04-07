#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long b, y;
    cin >> b >> y;
    long long m = 0;
    while(m*y+(m/2)*(m/2)+((m+1)/2)*((m+1)/2) <= b)
        m++;
    m--;
    cout << (1ll<<m) << "\n";
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