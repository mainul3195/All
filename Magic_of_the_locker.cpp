#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long Pow(long long b, long long p)
{
    if (!p)
        return 1;
    long long tmp = Pow(b, p / 2);
    tmp = tmp * tmp % mod;
    if (p & 1)
        tmp = tmp * b % mod;
    return tmp;
}
void solve()
{
    long long n;
    cin >> n;
    long long no_of_segments = max(1LL, (n + 1) / 3);
    long long value_of_a_segment = n / no_of_segments % mod;
    long long extra_one_added_segments = n % no_of_segments;
    long long ans = Pow(value_of_a_segment, no_of_segments - extra_one_added_segments) * Pow(value_of_a_segment + 1, extra_one_added_segments) % mod;
    cout << ans << "\n";
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