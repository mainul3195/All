#include<bits/stdc++.h>
using namespace std;
int n;
long long k, mn;
vector<long long> v, cmsum;
bool possible(long long x)
{
    if(x>=k) return 1;
    for(int i = n-1; i>=0; i--)
    {
        long long done = n - i;
        if(!i) done--;
        if(done>x) break;
        long long dcrs = x-done;
        if(cmsum[i]+dcrs*done + dcrs>=k) return 1;
    }
    return 0;
}
void solve()
{
    cin >> n >> k;
    v = vector<long long> (n);
    cmsum = vector<long long> (n);
    for(auto &i: v)
        cin >> i;
    long long sum = 0;
    for(auto i: v)
        sum += i;
    if(sum<=k)
    {
        cout << "0\n";
        return;
    }
    k = sum - k;
    sort(v.begin(), v.end());
    mn = v[0];
    for(auto &i: v)
        i -= mn;
    cmsum[n-1] = v[n-1];
    for(int i = n-2; i>=0; i--)
        cmsum[i] = cmsum[i+1]+v[i];
    long long ans = 100000000000000000;
    long long l = 0, r = ans, mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(possible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}