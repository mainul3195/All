#include <bits/stdc++.h>
using namespace std;
struct point
{
    long long x, y;
    int ind;
    bool operator<(const point &a) const
    {
        return x < a.x || (x == a.x && y < a.y);
    }
};
long long orientation(point a, point b, point c)
{
    long long x1 = b.x - a.x;
    long long y1 = b.y - a.y;
    long long x2 = c.x - b.x;
    long long y2 = c.y - b.y;
    return x1 * y2 - y1 * x2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> v(n);
    vector<bool> taken(n + 1, 0);
    vector<point> hull;
    int c = 1;
    for (auto &[x, y, i] : v)
    {
        cin >> x >> y;
        i = c++;
    }
    point min_pt = {2000000000, 2000000000, -1};
    for (auto p : v)
        if (p < min_pt)
            min_pt = p;
    hull.push_back(min_pt);
    taken[min_pt.ind] = true;
    while (hull.size() != n)
    {
        point cur = {-1, -1, -1};
        for (auto next : v)
            if (!taken[next.ind])
            {
                if (cur.x == -1)
                    cur = next;
                else
                {
                    if (orientation(hull.back(), cur, next) < 0)
                        cur = next;
                }
            }
        hull.push_back(cur);
        taken[cur.ind] = 1;
    }
    for (auto [_, __, i] : hull)
        cout << i << " ";
    cout << "\n";
    return 0;
}