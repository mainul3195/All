#include <bits/stdc++.h>
using namespace std;
#define pi (2 * acos(0.0))
void solve()
{
    double ad, cf, ef, abd, bdy, afc;
    cin >> ad >> cf >> ef >> abd >> bdy >> afc;
    abd *= pi / 180;
    bdy *= pi / 180;
    afc *= pi / 180;
    double ce = sqrt(cf * cf + ef * ef - 2 * cf * ef * cos(afc));
    double bita = acos((ce * ce + ef * ef - cf * cf) / (2 * ce  * ef));
    double bod = 2 * pi - 2 * bdy;
    double bd = ad * sin(bdy) / sin(abd);
    double ac = sin(bita) * ad / sin(abd);
    cout << fixed << setprecision(7) << ac * bd << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}