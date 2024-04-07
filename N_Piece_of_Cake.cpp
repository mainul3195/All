#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
struct pt 
{
    long double x, y;
};
long double cross(pt a, pt b)
{
    return a.x*b.y - a.y*b.x;
}
int n, k;
int main()
{
    cin >> n >> k;
    vector<pt>v(n);
    for(auto &i: v)
        cin >> i.x >> i.y;
    long double comb[n+2][n+2] = {0};
    for(int i = 0; i <= n; i++)
        comb[0][i] = 0, comb[i][0] = 1;
    comb[0][0] = 1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
            comb[i][j] = (i==j?0:comb[i-1][j])+comb[i-1][j-1];
    }
    long double ans = 0;
    for(int i = 0; i<n; i++)
        for(int j = k-1; j<n; j++)
            ans += cross(v[i], v[(i+j)%n])*comb[j-1][k-2]/comb[n][k];
    cout << fixed << setprecision(7) << ans/2 << "\n";
    return 0;
}