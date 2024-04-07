#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int bad;
    cin >> bad;
    for (int i = 0; i < bad; i++)
    {
        int hudai;
        cin >> hudai;
    }
    int avai = 10 - bad;
    cout << avai * (avai - 1) * 3 << "\n";
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