#include<bits/stdc++.h>
using namespace std;
long long find_time(long long x, long long r)
{
    if(x>=r)
        return r;
    return x + (r-x)*2;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long x, r, m;
        cin >> x >> r >> m;
        r*=60;
        m*=60;
        if(find_time(x, r)<=m)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}