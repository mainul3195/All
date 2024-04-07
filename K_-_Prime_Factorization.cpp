#include <bits/stdc++.h>
using namespace std;
#define lim 1100000
int f[lim];
vector<long long> primes;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for (int i = 3; i * i < lim; i++)
        if (!f[i])
            for (int j = i * i; j < lim; j += 2 * i)
                f[j] = 1;
    primes.push_back(2);
    for (int i = 3; i < lim; i += 2)
        if (!f[i])
            primes.push_back(i);
    vector<long long> factors;
    for (auto i : primes)
    {
        if (i * i > n)
            break;
        if (n % i == 0)
            factors.push_back(i);
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        factors.push_back(n);
    for (auto i : factors)
        cout << i << "\n";
    return 0;
}