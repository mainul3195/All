#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int oc = 0, ec = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (j & 1)
            oc++;
        else
            ec++;
    }
    cout << min(oc, ec) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}