#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long l, r;
    cin >> l >> r;
    long long ans = 10000;
    if(l/2019 != r/2019)
        cout << "0\n";
    else
    {
        for(long long i=l; i<r; i++)
            for(long long j=i+1; j<=r; j++)
                ans = min(ans, (i*j)%2019);
        cout << ans << "\n";
    }
    return 0;
}