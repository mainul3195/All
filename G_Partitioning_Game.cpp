#include <bits/stdc++.h>
using namespace std;
#define lim 10000
int grundy[lim + 2];
void calc_grundy()
{
    for (int i = 3; i <= lim; i++)
    {
        int mid = (i + 1) / 2;
        bool done[lim + 2] = {0};
        for (int j = 1; j < mid; j++)
            done[grundy[j] ^ grundy[i - j]] = 1;
        int k = 0;
        while (done[k])
            k++;
        grundy[i] = k;
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Xor ^= grundy[x];
    }
    if (Xor)
        cout << "Alice\n";
    else
        cout << "Bob\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    grundy[0] = grundy[1] = grundy[2] = 0;
    calc_grundy();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}