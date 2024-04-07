#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, q;
vector<int> times;
#define lim 100005
vector<long long> spf(lim + 1);
void smallest_pf()
{
    spf[1] = 1;
    for (long long i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (long long i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (long long j = i * i; j <= lim; j += 2 * i)
                spf[j] = i;
    for (int i = 3; i <= lim; i += 2)
        if (!spf[i])
            spf[i] = i;
    return;
}
void solve()
{
    cin >> n >> m >> q;
    times = vector<int>(m + 1, 0);
    vector<int> v, p(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        if (a == 1)
        {
            times[1]++;
            continue;
        }
        vector<int> tmp;
        while (a > 1)
        {
            int smallest_prime_factor = spf[a];
            int mul = 1;
            while (!(a % smallest_prime_factor))
            {
                a /= smallest_prime_factor;
                mul *= smallest_prime_factor;
            }
            times[mul]++;
            p[smallest_prime_factor]++;
            tmp.push_back(smallest_prime_factor);
        }
        if (tmp.size() > 1)
            times[v.back()]++;
    }
    for (int i = 0; i <= m; i++)
        cout << i << " -> " << times[i] << "\n";
    cout << "\n\n";
    for (int i = 0; i <= m; i++)
        cout << i << " -> " << p[i] << "\n";
    sort(v.begin(), v.end());
    // 1 handling
    int one = 0;
    for (int i = 1; i <= m; i++)
        if (times[i])
        {
            if (i == 1)
            {
                one += times[i] * (times[i] - 1) / 2 + n - times[i];
                // cout << "i = " << i << "\t" << one << "\n";
                continue;
            }
            int tmp = i;
            while (tmp > 1)
            {
                int iii = spf[tmp];
                one += n - p[iii];
                while (!(tmp % iii))
                    tmp /= iii;
            }
            // cout << "i = " << i << "\t" << one << "\n";
        }
    cout << one << "\n";
    one += upper_bound(v.begin(), v.end(), 1) - lower_bound(v.begin(), v.end(), 1);
    cout << "after -> " << one << "\n";
    while (q--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            cout << one << "\n";
            continue;
        }
        int count = 0;
        for (int mul = k * k; mul <= m; mul *= k)
            count += times[mul];
        int self = upper_bound(v.begin(), v.end(), k) - lower_bound(v.begin(), v.end(), k);
        int ans = 2 * (times[k] * count + times[k] * (times[k] - 1) / 2) + self;
        cout << ans << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    smallest_pf();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}