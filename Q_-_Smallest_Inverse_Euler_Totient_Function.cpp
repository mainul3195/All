#include <bits/stdc++.h>
using namespace std;
#define limN 100000002
#define limM 202918037
int phi[limM + 2], piInv[limN + 2];
void make()
{
    for (int i = 0; i <= limM; i++)
        phi[i] = i;
    for (int i = 2; i <= limM; i++)
        if (phi[i] == i)
            for (int j = i; j <= limM; j += i)
                phi[j] -= phi[j] / i;
    for (int i = 1; i <= limM; i++)
        if (phi[i] <= limN && !piInv[phi[i]])
            piInv[phi[i]] = i;
    cout << "ok\n";
    return;
}
// void solve()
// {
//     int n;
//     cin >> n;
//     cout << (piInv[n] ? piInv[n] : -1) << "\n";
//     return;
// }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make();
    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
    return 0;
}