#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long h, w;
    cin >> h >> w;
    long long mn = LONG_LONG_MAX;
    if (h % 3 == 0 || w % 3 == 0)
        mn = 0;
    if (mn)
        for (long long i = 1; i < h; i++)
        {
            long long tmp = max({i * w, (h - i) * (w / 2), (h - i) * (w - w / 2)}) - min({i * w, (h - i) * (w / 2), (h - i) * (w - w / 2)});
            if (tmp < mn)
            {
                mn = tmp;
            }
        }
    if (mn)
        for (long long i = 1; i < w; i++)
        {
            long long tmp = max({i * h, (w - i) * (h / 2), (w - i) * (h - h / 2)}) - min({i * h, (w - i) * (h / 2), (w - i) * (h - h / 2)});
            if (tmp < mn)
            {
                mn = tmp;
            }
        }
    if (mn)
        mn = min({mn, w, h});
    cout << mn << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}