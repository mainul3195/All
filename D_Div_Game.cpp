#include <bits/stdc++.h>
using namespace std;
#define lim 2000000
bitset<lim / 2 + 1> bt;
vector<long long> primes;
void sieve()
{
    primes.push_back(2);
    for (int i = 3; i * i <= lim; i += 2)
        if (!bt[i / 2])
            for (int j = i * i; j <= lim; j += 2 * i)
                bt[j / 2] = 1;
    for (int i = 3; i < lim; i += 2)
        if (!bt[i / 2])
            primes.push_back(i);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    vector<int> v(40);
    int tot = 1;
    for (int i = 2; tot < 40; i++)
    {
        v[tot]++;
        tot += i;
    }
    for (int i = 1; i < 40; i++)
        v[i] += v[i - 1];
    long long n;
    cin >> n;
    long long ans = 0;
    for (auto p : primes)
    {
        if (p * p > n)
            break;
        int count = 0;
        while (n % p == 0)
        {
            count++;
            n /= p;
        }
        ans += v[count];
    }
    if (n > 1)
        ans++;
    cout << ans << "\n";
    return 0;
}