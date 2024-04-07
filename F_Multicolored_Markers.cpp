#include <bits/stdc++.h>
using namespace std;
vector<long long> divisors(long long n)
{
    vector<long long> v;
    long long s = sqrt(n + .5);
    while (s > 0)
    {
        if (n % s == 0)
        {
            v.push_back(s);
            if (s != n / s)
                v.push_back(n / s);
        }
        s--;
    }
    sort(v.begin(), v.end());
    return v;
}
bool possible(long long d1, long long d2, vector<long long> &v, long long a)
{
    auto it = upper_bound(v.begin(), v.end(), d1);
    it--;
    return a / (*it) <= d2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, s;
    cin >> a >> b;
    s = a + b;
    vector<long long> da = divisors(a), db = divisors(b);
    long long l = sqrt(s + .5);
    while (l > 0)
    {
        if (s % l == 0)
        {
            if (possible(l, s / l, da, a) || possible(l, s / l, db, b))
            {
                cout << 2 * (l + s / l) << "\n";
                return 0;
            }
        }
        l--;
    }
    return 0;
}