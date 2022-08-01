#include <bits/stdc++.h>
using namespace std;
#define eps 1e-9
struct pt
{
    int x, y;
    bool operator<(const pt &a) const
    {
        return y < a.y || (y == a.y && x < a.x);
    }
    pt operator-(const pt &a) const
    {
        return {x - a.x, y - a.y};
    }
    int operator*(const pt &a) const
    {
        return x * a.y - y * a.x;
    }
};
double dist(pt a, pt b) //distance between two points
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double find(pt a, pt b, pt c) // perpendicular distance from pont c to line containing a & b
{
    double dis = (c.x * (a.y - b.y) + c.y * (b.x - a.x) + a.x * b.y - b.x * a.y) / sqrt((a.y - b.y) * (a.y - b.y) + (b.x - a.x) * (b.x - a.x));
    if (0 - dis > eps)
        return -dis;
    return dis;
}
int orient(pt a, pt b, pt c)
{
    int cross = (b - a) * (c - a);
    return (!cross ? 0 : (cross < 0 ? -1 : 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tc = 0;
    while (cin >> n && n)
    {
        cout << "Case " << ++tc << ": ";

        vector<pt> v(n), points;
        for (auto &i : v)
            cin >> i.x >> i.y;


        //if the given orientation is anticlockwise, making it clockwise
        long long area = 0;
        for (int i = 0; i < n; i++)
            area += v[i] * v[(i + 1) % n];
        if (area < 0)
        {
            int i = 1, j = n - 1;
            for (; i < j; i++, j--)
                swap(v[i], v[j]);
        }

        //finding the lowest point
        int low;
        pt lowest = {2000000000, 2000000000};
        for (int i = 0; i < n; i++)
            if (v[i] < lowest)
            {
                lowest = v[i];
                low = i;
            }


        //making convex hull
        int cur = low, next = (cur + 1) % n;
        int count = 0;
        bool first_time = 1;
        while (first_time || cur != low)
        {
            first_time = 0;
            points.push_back(v[cur]);

            for (int i = 0; i < n; i++)
                if (i != cur && i != next && (orient(v[cur], v[next], v[i]) < 0 || (orient(v[cur], v[next], v[i]) == 0 && fabs(dist(v[cur], v[next]) + dist(v[next], v[i]) - dist(v[cur], v[i])) < eps)))
                    next = i;
            cur = next;
            next = (next + 1) % n;
        }


        //finding minimum diameter of the convex hull
        double ans = 1e10;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            double mx = 0;
            for (int j = 0; j < n; j++)
                if (i != j && j != i + 1)
                    mx = max(mx, find(points[i], points[(i + 1) % n], points[j]));
            ans = min(ans, mx);
        }

        //formatting output
        ans *= 100;
        if (ans - (int)ans > eps)
            ans++;
        cout << fixed << setprecision(2) << (double)ans / 100 << "\n";
    }
    return 0;
}