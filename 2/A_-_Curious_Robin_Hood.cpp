// using bit

#include <bits/stdc++.h>
using namespace std;
vector<int> bit;
int n, q;
void update(int x, int val)
{
    for (int i = x; i <= n; i += i & (-i))
        bit[i] += val;
}
int sum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= i & (-i))
        sum += bit[i];
    return sum;
}
void solve()
{
    cin >> n >> q;
    bit = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int ind;
            cin >> ind;
            ind++;
            int s = sum(ind) - sum(ind - 1);
            cout << s << "\n";
            update(ind, -s);
        }
        else if (t == 2)
        {
            int ind, val;
            cin >> ind >> val;
            ind++;
            update(ind, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l++, r++;
            cout << sum(r) - sum(l - 1) << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}