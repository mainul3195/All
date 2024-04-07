#include <bits/stdc++.h>
using namespace std;
struct point
{
    double x, y, z, dist;
};
vector<point> v;
bool possible(double r, double h)
{
    for (auto [_, __, y, x] : v)
    {
        double a1 = -r;
        double b1 = h;
        double a2 = x - r;
        double b2 = y;
        double cross = a1 * b2 - b1 * a2;
        if (fabs(cross) < 1e-9)
            continue;
        if (cross < 0)
            return false;
    }
    return true;
}
double calc_h(double r)
{
    double start = 0, end = 1e9, mid;
    while (end - start > 1e-9)
    {
        mid = (start + end) / 2;
        if (possible(r, mid))
            end = mid;
        else
            start = mid;
    }
    return (start + end) / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("dome.in", "r", stdin);
    // freopen("dome.out", "w", stdout);
    int n;
    cin >> n;
    v = vector<point>(n);
    double mx = 0;
    for (auto &[x, y, z, d] : v)
    {
        cin >> x >> y >> z;
        d = sqrt(x * x + y * y);
        mx = max(mx, d);
    }
    double start = mx, end = 1e9, mid1, mid2;
    while (end - start > 1e-9)
    {
        mid1 = (start + (end - start) / 3);
        mid2 = (start + 2 * (end - start) / 3);
        double h1 = calc_h(mid1);
        double h2 = calc_h(mid2);
        double volume1 = mid1 * mid1 * h1;
        double volume2 = mid2 * mid2 * h2;
        if (volume1 < volume2)
            end = mid2;
        else
            start = mid1;
    }
    double radious = (start + end) / 2;
    cout << fixed << setprecision(3) << calc_h(radious) << " " << radious << "\n";
    return 0;
}