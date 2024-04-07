#include <bits/stdc++.h>
using namespace std;
#define lim 10000020
bitset<lim / 2 + 2> f;
vector<int> bit;
int n, q;
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= n; x += (x & (-x)))
        bit[x] += val;
}
void make_primes()
{
    for (int i = 3; i * i < lim; i += 2)
        if (!f[i / 2])
            for (int j = i * i; j < lim; j += 2 * i)
                f[j / 2] = 1;
    return;
}
bool isPrime(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return (n % 2 != 0) && (!f[n / 2]);
}
void solve()
{
    cin >> n >> q;
    bit = vector<int>(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (isPrime(x))
            upd(i, 1 - (qr(i) - qr(i - 1)));
    }
    while (q--)
    {
        int t, ind;
        cin >> t >> ind;
        if (t == 1)
        {
            // left
            int l = 1, r = ind - 1, mid, ans1 = 0;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (qr(ind - 1) - qr(mid - 1) == 0)
                {
                    ans1 = ind - mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }

            // right
            l = ind + 1, r = n;
            int ans2 = 0;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (qr(mid) - qr(ind) == 0)
                {
                    ans2 = mid - ind;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            cout << ans1 + ans2 << "\n";
        }
        else
        {
            int val;
            cin >> val;
            if (isPrime(val))
                upd(ind, 1 - (qr(ind) - qr(ind - 1)));
            else
                upd(ind, -(qr(ind) - qr(ind - 1)));
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_primes();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}