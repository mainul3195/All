#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        int nm = a[i];
        int count = 0;
        while (i < n && a[i] == nm)
        {
            count++;
            i++;
        }
        i--;
        if (count > 1)
        {
            if (l == -1)
                l = i - count + 1;
            r = i;
        }
    }
    if (r - l <= 1)
        cout << "0\n";
    else if (r - l == 2)
        cout << "1\n";
    else
        cout << r - l - 2 << "\n";
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