#include<bits/stdc++.h>
using namespace std;

void solve()
{
    double a, d;
    cin >> a >> d;
    cout << fixed << setprecision(9) <<  d / (8 * acos(0.0)) << "\n";
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