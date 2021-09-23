#include<bits/stdc++.h>
using namespace std;
int n;
long long calc(vector<int> &v)
{
    int mn=v[0], mx=v[0];
    long long ans = 0;
    for(int j=1; j<n;  j++)
    {
        mn=min(mn, v[j]);
        mx = max(mx, v[j]);
        ans += mx - mn;
    }
    return ans;
}
void solve()
{
    cin >> n;
    vector<int> num(n), dif(n-1);
    for(auto &i: num)
        cin >> i;
    sort(num.begin(), num.end());
    vector<int>v;
    long long ans =LONG_MAX;
    for(int i=0; i<n; i++)
    {
        v.clear();
        v.assign(n, 0);
        int left, right;
        int j=1;
        v[0]=num[i];
        left = i-1;
        right = i+1;
        while(1)
        {
            if(left == -1 && right == n)
                break;
            if(left == -1)
                v[j++] = num[right++];
            else if(right == n)
                v[j++] = num[left--];
            else
            {
                if(num[i]-num[left]>=num[right]-num[i])
                    v[j++]=num[right++];
                else
                    v[j++]=num[left--];
                
            }
        }
        long long temp = calc(v);
        for(auto k:v)
            cout << k << " ";
        cout << temp << "\n";

        ans = min(ans, temp);
    }

    cout << ans << "\n";
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}