#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for(int i=1; i<=n; i++)
    {
        double temp = 1;
        for(int j=i;j<k; j*=2)
            temp *= .5;
        ans += temp;
    }
    cout <<fixed << setprecision(12) << ans/n << "\n";
    return 0;
}