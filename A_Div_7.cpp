#include <bits/stdc++.h>
using namespace std;
int diff(int a, int b)
{
    int nd1 = 0, nd2 = 0, x = a, y = b;
    while (x)
    {
        nd1++;
        x /= 10;
    }
    while (y)
    {
        nd2++;
        y /= 10;
    }
    if (nd1 != nd2)
        return 100;
    int count = 0;
    while (a)
    {
        int r1 = a % 10, r2 = b % 10;
        if (r1 != r2)
            count++;
        a /= 10;
        b /= 10;
    }
    return count;
}
void solve()
{

    int n;
    cin >> n;
    int mnd = 5, val = -1;
    for (int i = 14; i <= 999; i += 7)
    {
        int d = diff(i, n);
        if (d < mnd)
        {
            mnd = d;
            val = i;
        }
    }
    cout << val << "\n";
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