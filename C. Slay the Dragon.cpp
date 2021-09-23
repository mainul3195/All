#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
vector<long long>v;
int n;
int mnfind(long long x)
{
    int l = 0, r = n-1, ans = -1, mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(v[mid]<x)
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid - 1;
    }
    return ans;
}
int mxfind(long long x)
{
    int l = 0, r = n-1, ans = n, mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(v[mid]<x)
            l = mid+1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    v = vector<long long>(n);
    long long sum = 0;
    for(auto &i: v)
    {
        cin >> i;
        sum += i;
    }
    sort(all(v));
    int m;
    long long x,y;
    cin >> m;
    while(m--)
    {
        cin >> x >> y;
        long long l = v[max(0, mnfind(x))];
        long long r = v[min(n-1, mxfind(x))];
        cout << min(max(0ll, x-l)+max(0ll, y-sum+l), max(0ll, x-r)+max(0ll, y-sum+r)) << "\n";
    }

    return 0;
}
/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
*/