#include <bits/stdc++.h>
using namespace std;
long long find_grundy(long long x)
{
    if (x == 1)
        return 0;
    if (x % 2 == 0)
        return x / 2;
    return find_grundy(x - x / 2 - 1);
}
void solve()
{
    int n;
    cin >> n;
    unsigned long long Xor = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        Xor ^= find_grundy(x);
    }
    if (Xor)
        cout << "YES\n";
    else
        cout << "NO\n";
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