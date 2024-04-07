#include <iostream>
using namespace std;
struct pt
{
    int x, y;
    void inp()
    {
        cin >> x >> y;
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
int orientation(pt a, pt b, pt c)
{
    int crs = ((b - a) * (c - a));
    return (!crs ? 0 : (crs < 0 ? -1 : 1));
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
    int t;
    cin >> t;
    while (t--)
    {
        pt sgs, sge, lt, rb;
        sgs.inp(), sge.inp(), lt.inp(), rb.inp();
        if (intersect(sgs, sge, lt, {rb.x, lt.y}) || intersect(sgs, sge, lt, {lt.x, rb.y}) || intersect(sgs, sge, rb, {rb.x, lt.y}) || intersect(sgs, sge, rb, {lt.x, rb.y}))
            cout << "T\n";
        else
            cout << "F\n";
    }
    return 0;
}