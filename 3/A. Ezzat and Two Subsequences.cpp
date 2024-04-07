#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long mx = -2000000000;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            long long j;
            cin >> j;
            mx = max(mx, j);
            sum += j;
        }
        cout << fixed << setprecision(9) <<  (double)mx + (double)(sum-mx)/(n-1) << "\n";
    }
    return 0;
}