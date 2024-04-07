#include <iostream>
#include <iomanip>
using namespace std;

void solve()
{
    long long x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    long long m1 = (y1 - y2) * (x3 - x4);
    long long m2 = (x1 - x2) * (y3 - y4);
    long long c1 = (x1 * y2 - x2 * y1) * (x3 - x4);
    long long c2 = (x3 * y4 - x4 * y3) * (x1 - x2);
    if (m1 == m2)
    {
        if ((x2-x1)*(y4-y1) == (x4-x1)*(y2-y1))
            cout << "LINE\n";
        else
            cout << "NONE\n";
    }
    else
    {
        cout << "POINT ";
        cout << fixed << setprecision(2) << (double)(c2 - c1) / (m1 - m2) << " " << (double)((x3 * y4 - x4 * y3) * (y1 - y2) - (x1 * y2 - x2 * y1) * (y3 - y4)) / (m1 - m2) << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "INTERSECTING LINES OUTPUT\n";
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    cout << "END OF OUTPUT\n";
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/