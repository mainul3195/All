#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
vector<int> v, divisors;
void solve()
{
    int n;
    cin >> n;
    int last;
    v.push_back(n);
    do
    {
        v.push_back(n);
        mp[n] = 1;
        cout << "+ " << n << endl;
        cin >> n;
        last = n;
    } while (!mp.count(n));
    long long sum = n;
    while (v.back() != n)
    {
        sum += v.back();
        v.pop_back();
    }
    for (int i = 1; i * i <= sum; i++)
        if (sum % i == 0)
        {
            divisors.push_back(i);
            if (i * i != sum)
                divisors.push_back(sum / i);
        }
    sort(divisors.begin(), divisors.end());
    int x = -1;
    int ans;
    do
    {
        if (~x)
        {
            last = x;
            ans = divisors.back();
            divisors.pop_back();
        }
        cout << "+ " << divisors.back() << endl;

        cin >> x;
    } while (x == last);
    cout << "! " << ans << "\n";
    return;
}
int32_t main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}