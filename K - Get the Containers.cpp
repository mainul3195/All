#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++tc << ": ";
        int n,m;
        cin >> n >> m;
        vector<long long> v(n);
        long long l=0, r=0, mid;
        for(int i=0; i<n; i++)
        {
            cin >> v[i];
            l=max(v[i], l);
            r+=v[i];
        }
        while(l<=r)
        {
            mid=(l+r) >> 1;
            long long division=1, sum=0;
            for(int i=0; i<n; i++)
            {
                if(sum+v[i]>mid)
                {
                    division++;
                    sum=v[i];
                }
                else 
                    sum+=v[i];
            }
            if(division <= m)
                r=mid-1;
            else 
                l=mid+1;
        }
        cout << l << "\n";
    }
    return 0;
}