#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        cout << "Case " << ++tc << ": ";
        int n, k;
        cin >> n >> k;
        vector<long long> v(n+1);
        long long l=0, r=0, mid;
        for(int i=0; i<=n; i++)
        {
            cin >> v[i];
            l=max(l, v[i]);
            r+=v[i];
        }
        long long ans,sum;
        while(l<=r)
        {
            mid=(l+r) >> 1;
            long long divide=0;
            sum=0;
            for(int i=0; i<=n; i++)
            {
                if(sum+v[i]>mid)
                {
                    sum=v[i];
                    divide++;
                }
                else
                {
                    sum+=v[i];
                }
            }
            if(divide<=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        cout << ans << "\n";
        sum=0;
        int count=0;
        for(int i=0; i<=n; i++)
        {
            if(sum+v[i]>ans)
            {
                cout << sum << "\n";
                sum=0;
                count++;
            }
            //cout << "\t" << k+1-count << " " << v.size()-i << " " << i << "\n";
            if(k+1-count == v.size()-i)
            {
                cout << sum+v[i] << "\n";
                for(int j=i+1; j<=n; j++)
                    cout << v[j] << "\n";
                break;
            }
            sum+=v[i];
        }
    }
    return 0;
}
/*
42
52
53
65
59
64
22
*/