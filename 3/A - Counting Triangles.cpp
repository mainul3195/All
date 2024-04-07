#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int pos(vector<int> &v, int num)
{
    int l=0, r=n-1, mid;
    int ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(v[mid]<num)
        {
            ans=mid;
            l=mid+1;
        }
        else 
            r=mid-1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int count=0;
        auto it = v.begin();
        for(int i=0; i<n-2; i++, it++)
            for(int j=i+1; j<n-1; j++)
            {
                int temp=v[i]+v[j];
                int x = (pos(v, temp) - j);
                count += x;
            }
        cout <<"Case " << ++tc << ": " <<  count << "\n";
    }
    return 0;
}