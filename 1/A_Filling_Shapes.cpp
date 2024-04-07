#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2)
        cout << "0\n";
    else
        cout << (long long)(pow(2, n / 2) + .05) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}