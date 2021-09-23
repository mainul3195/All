#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> radius(n);
    for (auto &i: radius)
        cin >> i;
    sort(all(radius));
    reverse(all(radius));
    radius.push_back(0);
    double ans = 0;
    for(int i=0; i<radius.size()-1; i+=2)
        ans += pi*(radius[i]*radius[i]-radius[i+1]*radius[i+1]);
    cout << fixed << setprecision(8) << ans << "\n";

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
*/