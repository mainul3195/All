#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long w, h, x, y;
    cin >> w >> h >> x >> y;
    cout << fixed << setprecision(12) << w*h/2.0 << " " <<  "01"[(x+x == w && y+y ==h)] << "\n";
    return 0;
}