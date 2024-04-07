#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int>> v;
void calc(long long p = 9, int tern = 0)
{
    v.push_back({p, !tern});
    if (p > 4294967295)
        return;
    calc(p * (tern ? 9 : 2), !tern);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calc();
    long long n;
    while (cin >> n)
    {
        auto [a, b] = *upper_bound(v.begin(), v.end(), pair<long long, int>{n, -1});
        if (b)
            cout << "Stan wins.\n";
        else
            cout << "Ollie wins.\n";
    }
    return 0;
}