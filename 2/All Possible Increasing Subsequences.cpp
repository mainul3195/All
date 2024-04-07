#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
#define inf 1000000000000000000
#define Left(x) (x<<1)
#define Right(x) (Left(x)+1)
#define Mid(x,y) ((x+y)>>1)
struct nd{
    long long val,index;
    bool operator < (const nd &a) const
    {
        return ((val<a.val) || ((val == a.val) && (index < a.index)));
    }
};
vector<nd>v;
vector<long long>bit;
int n;
void update(int index, int val, int node = 1, int start = 1, int end = n)
{
    sg_tree[node] = (sg_tree[node] + val);
    if(start == end) return;
    index<=Mid(start, end)? update(index, val, Left(node), start, Mid(start, end)) : update(index, val, Right(node), Mid(start, end)+1, end);
}
long long sum(int l, int r, int node = 1, int start=1, int end = n)
{
    if(r<start || end<l)    return 0;
    if(start>=l && end <= r) return sg_tree[node];
    return (sum(l, r, Left(node), start, Mid(start, end))+sum(l, r, Right(node), Mid(start, end)+1, end));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        v.clear();
        v.push_back({-inf,-inf});
        bit = vector<long long>(n, 0);
        for(int i=1; i<=n; i++)
        {
            int j;
            cin >> j;
            v.push_back({j,i});
        }
        sort(v.begin(), v.end());
        map<long long, long long> mp;
        for(int i=1; i<=n; i++)
        {
            long long temp = sum(1,v[i].index-1);
            update(v[i].index, 1+temp - mp[v[i].val]);
            mp[v[i].val] = 1+temp;
        }

        cout << "Case " << ++tc << ": " << sum(1,n) << "\n";
    }
    return 0;
}