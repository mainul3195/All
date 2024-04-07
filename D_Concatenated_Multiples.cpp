#include <bits/stdc++.h>
using namespace std;
int len(int a)
{
    int cnt = 0;
    while (a)
    {
        cnt++;
        a /= 10;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    unordered_map<int, int> mp[11];
    long long ans = 0;
    for (auto a : v)
    {
        int ln = len(a);
        int fnd = (k - a % k) % k;
        ans += mp[ln][fnd];
        for (int i = 1; i <= 10; i++)
        {
            a *= 10;
            a %= k;
            mp[i][a]++;
        }
    }
    for (int ln = 0; ln < 11; ln++)
        mp[ln].clear();
    reverse(v.begin(), v.end());
    for (auto a : v)
    {
        int ln = len(a);
        int fnd = (k - a % k) % k;
        ans += mp[ln][fnd];
        for (int i = 1; i <= 10; i++)
        {
            a *= 10;
            a %= k;
            mp[i][a]++;
        }
    }
    cout << ans << "\n";

    return 0;
}