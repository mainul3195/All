#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long sum = 0;
    for (int i = 0; i < 7; i++)
    {
        int n;
        cin >> n;
        sum += n;
    }
    cout << sum << "\n";
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