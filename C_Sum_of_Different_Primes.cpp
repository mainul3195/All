#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}
vector<long long> primes;
void make_primes()
{
    primes.push_back(2);
    for (int i = 3; i < 2000; i += 2)
        if (is_prime(i))
            primes.push_back(i);
    return;
}
int n, k;
long long dp[300][20][1500];
long long solve(int i = 0, int item_rem = k, int val_rem = n)
{
    if (item_rem == 0 && val_rem == 0)
        return 1;
    if (!item_rem)
        return 0;
    if (primes[i] > val_rem)
        return 0;
    if (~dp[i][item_rem][val_rem])
        return dp[i][item_rem][val_rem];
    return dp[i][item_rem][val_rem] = solve(i + 1, item_rem, val_rem) + solve(i + 1, item_rem - 1, val_rem - primes[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    make_primes();
    while (cin >> n >> k && (n || k))
        cout << solve() << "\n";
    return 0;
}