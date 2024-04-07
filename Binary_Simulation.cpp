#include <bits/stdc++.h>
using namespace std;
int ar[400000];
void update(int cur, int l, int r, int ql, int qr)
{
    if (qr < l || ql > r)
        return;
    if (l >= ql && r <= qr)
    {
        ar[cur] = !ar[cur];
        return;
    }
    int left = cur * 2;
    int right = left + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, ql, qr);
    update(right, mid + 1, r, ql, qr);
}
int query(int cur, int l, int r, int q)
{
    if (q < l || q > r)
        return 0;
    if (l == r)
        return ar[cur];

    int left = cur * 2;
    int right = left + 1;
    int mid = (l + r) / 2;
    int ans1 = query(left, l, mid, q);
    int ans2 = query(right, mid + 1, r, q);
    return ans1 + ans2 + ar[cur];
}
void solve()
{
    string s;
    cin >> s;
    for (int i = 1; i <= s.size() * 4; i++)
        ar[i] = 0;
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'I')
        {
            int l, r;
            cin >> l >> r;
            update(1, 1, s.size(), l, r);
        }
        else
        {
            int ind;
            cin >> ind;
            cout << (s[ind - 1] - '0' + query(1, 1, s.size(), ind)) % 2 << "\n";
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