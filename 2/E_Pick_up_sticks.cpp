#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define eps 1e-9
using namespace std;
struct pt
{
    double x, y;
    pt operator-(const pt &a) const
    {
        return {x - a.x, y - a.y};
    }
    double operator*(const pt &a) const
    {
        return x * a.y - y * a.x;
    }
};
struct ln
{
    pt start, end;
    void inp()
    {
        cin >> start.x >> start.y >> end.x >> end.y;
    }
};
int orientation(pt a, pt b, pt c)
{
    double crs = ((b - a) * (c - a));
    return (fabs(crs) < eps ? 0 : (crs < eps ? -1 : 1));
}
bool intersect(pt a, pt b, pt c, pt d)
{
    if ((orientation(a, b, c) != orientation(a, b, d)) && (orientation(c, d, a) != orientation(c, d, b)))
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n)
    {
        vector<ln> lines(n);
        vector<int> done(n, 0);
        for (auto &i : lines)
            i.inp();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (intersect(lines[i].start, lines[i].end, lines[j].start, lines[j].end))
                {
                    done[i] = 1;
                    break;
                }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!done[i])
                ans.push_back(i + 1);
        cout << "Top sticks: ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i == ans.size() - 1)
                cout << ".\n";
            else
                cout << ", ";
        }
    }
    return 0;
}