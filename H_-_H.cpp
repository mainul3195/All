#include <bits/stdc++.h>
using namespace std;
struct p3
{
    double x, y, z;
    p3 operator*(p3 w)
    {
        return {y * w.z - z * w.y, z * w.x - x * w.z, x * w.y - y * w.x};
    }
    double val()
    {
        return sqrt(x * x + y * y + z * z);
    }
    double operator|(p3 w)
    {
        return x * w.x + y * w.y + z * w.z;
    }
    p3 operator-(p3 w)
    {
        return {x - w.x, y - w.y, z - w.z};
    }
    p3 operator/(double d)
    {
        return {x / d, y / d, z / d};
    }
};
int unit(double d)
{
    if (fabs(d) < 1e-9)
        return 0;
    if (d + 1e-9 > 0)
        return 1;
    return -1;
}
vector<p3> v;
void solve()
{
    int n;
    int tc = 0;
    while (cin >> n && n)
    {
        v = vector<p3>(n);
        for (auto &[x, y, z] : v)
            cin >> x >> y >> z;
        double ans = 0;
        for (int a = 0; a < n; a++)
            for (int b = a + 1; b < n; b++)
                for (int c = b + 1; c < n; c++)
                {
                    set<int> st;
                    p3 area = ((v[b] - v[a]) * (v[c] - v[a])) / 2;
                    for (int l = 0; l < n; l++)
                        if (l != a && l != b && l != c)
                            st.insert(unit((v[l] - v[a]) | area));
                    if (st.size() == 1)
                        ans += area.val();
                }
        cout << "Case " << ++tc << ": ";
        cout << fixed << setprecision(2) << ans << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}