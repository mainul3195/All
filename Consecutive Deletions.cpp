#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int k, n;
        cin >> n >> k;
        vector<int>v(n);
        int tot=0;
        for(int i=0; i<n; i++)
        {
            cin >> v[i];
            tot += v[i];
        }
        int mx_sum = 0, local_sum;
        for(int i=0; i<k; i++)
            mx_sum += v[i];
        local_sum = mx_sum;
        for(int i=k; i<n; i++)
        {
            local_sum += v[i]-v[i-k];
            if(local_sum<mx_sum)
                mx_sum = local_sum;
        }
        cout << (long long)tot-mx_sum + (long long)mx_sum*(mx_sum+1)/2 << "\n";
    }
    return 0;
}