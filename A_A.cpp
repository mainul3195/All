#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<double> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i] = v[i - 1] + log(x);
    }
    while (q--)
    {
        int l, r, p, m, k;
        cin >> l >> r >> p >> m >> k;
        double rhs = k * log(m);
        int s = l, e = r - 1, mid, ans = -1;
        while (s <= e)
        {
            mid = (s + e) / 2;
            double lhs = (v[mid] - v[l - 1] - (v[r] - v[mid])) * p;
            if (lhs >= rhs)
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        if (ans == -1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << ans << "\n";
        }
    }
    return 0;
}