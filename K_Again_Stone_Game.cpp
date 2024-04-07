#include <bits/stdc++.h>
using namespace std;
long long find_grundy(long long n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return n / 2;
    return find_grundy(n - n / 2 - 1);
}
void solve()
{
    int n;
    cin >> n;
    long long Xor = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        Xor ^= find_grundy(x);
    }
    if (Xor)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}