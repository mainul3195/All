#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long m = 1;
    vector<bool> cp(n + 1, 0);
    for (int i = 1; i < n; i++)
        if (__gcd(i, n) == 1)
        {
            cp[i] = 1;
            m = (m * i) % n;
        }
    if (m != 1)
        cp[m] = 0;
    cout << count(cp.begin(), cp.end(), true) << "\n";
    for (int i = 1; i < n; i++)
        if (cp[i])
            cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}