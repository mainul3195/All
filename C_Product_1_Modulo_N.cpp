#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long md = 1;
    vector<int> v(n, 0);
    int count = 0;
    for (int i = 1; i < n; i++)
        if (__gcd(i, n) == 1)
        {
            count++;
            v[i] = 1;
            md = (md * i) % n;
        }
    if (md != 1)
    {
        count--;
        v[md] = 0;
    }
    cout << count << "\n";
    for (int i = 1; i < n; i++)
        if (v[i])
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