#include<bits/stdc++.h>
using namespace std;
#define eps 1e-15
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n,k;
        cin >> n >> k;
        vector<long long> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        long long denominator=0;
        long long ans=0;
        for(long long i=1; i<n; i++)
        {
            denominator += v[i-1];
            if(((long double)v[i]/denominator)*100 + eps >  k )
            {
                long long required = (v[i]*100 + k -1)/k;
                ans += required - denominator;
                denominator = required;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}