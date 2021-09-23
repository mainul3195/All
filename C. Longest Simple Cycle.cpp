#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> c(n), a(n), b(n);
        for(int i=0; i<n; i++)
            cin >> c[i];
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];
        long long prev=0, ans=0;
        for(int i=1; i<n; i++)
        {
            if(a[i]==b[i])
                prev = 2;
            else
            {
                if(!prev)
                    prev=abs(a[i]-b[i])+2;
                else 
                    prev = max ( abs(a[i]-b[i]) + 2, prev + c[i-1] - abs(a[i]-b[i]) +1);
            }
            ans = max( ans, prev + c[i] -1);
        }
        cout << ans << "\n";
    }
    return 0;
}