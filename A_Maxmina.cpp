#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int count =0;
    for(int i = 0; i<n; i++)
    {
        int a;
        cin >>  a;
        if(a)
            count++;
    }
    if (count == n || (k<=n && count))
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}