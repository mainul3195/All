#include <bits/stdc++.h>
using namespace std;
#define lim 1100000
int f[lim];
vector<long long> primes;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 3; i * i < lim; i++)
        if (!f[i])
            for (int j = i * i; j < lim; j += 2 * i)
                f[j] = 1;
    primes.push_back(2);
    for (int i = 3; i < lim; i += 2)
        if (!f[i])
            primes.push_back(i);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        long long ans = 1;
        cin >> n;
        for (auto p : primes)
        {
            if (p > n)
                break;
            int tn = n;
            long long count = 1;
            while (tn > 1)
            {
                count += tn / p;
                tn /= p;
            }
            ans = (ans * count) % 1000000007;
        }
        cout << ans << "\n";
    }
    return 0;
}