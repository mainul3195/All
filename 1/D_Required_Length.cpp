#include <bits/stdc++.h>
using namespace std;
unsigned long long n, x;
int mx;
int no_of_digit(unsigned long long a)
{
    int count = 0;
    while (a)
    {
        a /= 10;
        count++;
    }
    return count;
}
map<unsigned long long, int> mp;
int okdone(unsigned long long t = x)
{
    if (no_of_digit(t) >= n)
        return 0;
    if (mp.count(t))
        return mp[t];
    int ar[10] = {0};
    unsigned long long a = t;
    while(a)
    {
        ar[a % 10] = 1;
        a /= 10;
    }
    int ans = 100;
    for (int i = 2; i < 10; i++)
        if (ar[i])
            ans = min(ans, okdone(t * i));
    return mp[t] = ans + 1;
}
void solve()
{
    cin >> n >> x;
    int ans = okdone();
    if (ans >= 100)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}