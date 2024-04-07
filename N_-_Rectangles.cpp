#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long ans = n;
    for (int i = 2; i <= n; i++)
        if(i*i<=n)
            ans += n/i - (i*i-1)/i;
    cout << ans << "\n";
    return 0;
}