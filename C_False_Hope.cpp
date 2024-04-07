#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v = {1, 2, 3, 4};
    do
    {
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}