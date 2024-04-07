#include <bits/stdc++.h>
using namespace std;
#define lim 1000006
vector<int> spf(lim + 1);
void build_spf()
{
    for (int i = 0; i <= lim; i++)
        spf[i] = i;
    for (int i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i <= lim; i += 2)
        if (spf[i] == i)
            for (int j = i; j <= lim; j += 2 * i)
                if (spf[j] == j)
                    spf[j] = i;
    return;
}
void solve()
{
    long long a, b;
    cin >> a >> b;
    long long gcd = __gcd(a, b);
    long long ans = 1;
    while (gcd > 1)
    {
        long long s = spf[gcd];
        int count = 0;
        while (gcd % s == 0)
        {
            count++;
            gcd /= s;
        }
        ans *= (count + 1);
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    build_spf();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}