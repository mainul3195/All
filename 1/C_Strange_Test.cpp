#include <bits/stdc++.h>
using namespace std;
vector<int> p2;
void solve()
{
    int a, b;
    cin >> a >> b;
    vector<bool> sa, sb;
    int n = a, m = b;
    while (n)
    {
        sa.push_back(n % 2);
        n >>= 1;
    }
    while (m)
    {
        sb.push_back(m % 2);
        m >>= 1;
    }
    int ans1 = 0, ind = -1;
    n = a, m = b;
    for (int i = sb.size() - 1; i >= 0; i--)
    {
        if (i >= sa.size())
        {
            if (sb[i])
                m -= p2[i];
        }
        else
        {
            if (sa[i] && !sb[i])
            {
                ind = i;
                ans1 = n - m;
                break;
            }
            if (sa[i])
                n -= p2[i];
            if (sb[i])
                m -= p2[i];
        }
    }
    // cout << ind << " ";
    n = a, m = b;
    for (ind++; ind < sb.size(); ind++)
        if (sb[ind] && (ind >= sa.size() || !sa[ind]))
            break;
    // cout << ind << " ";
    int last = (sa.size() == sb.size() || ind == sb.size() - 1);
    if (last)
    {
        // ind == sb.size() - 1;
        for (int i = ind + 1; i < sa.size(); i++)
            if (sa[i] != sb[i])
            {
                last = 0;
                break;
            }
    }
    for (int i = 0; i < ind; i++)
        if (sb[i])
        {
            last = 0;
            n += p2[i];
        }
    for (ind++; ind < sb.size(); ind++)
    {
        if (ind < sa.size() && sa[ind])
            n -= p2[ind];
        if (sb[ind])
            m -= p2[ind];
    }
    // cout << ans1 << " " << n << " " << m << "\n";
    cout << min(ans1, m - n - last) + 1 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    long long m = 1;
    while (m < 2000000000)
    {
        p2.push_back(m);
        m <<= 1;
    }
    cin >> t;
    while (t--)
        solve();
    return 0;
}