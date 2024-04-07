#include<bits/stdc++.h>
using namespace std;
int n;
#define Left(x) (x<<1)
#define Right(x) (Left(x)+1)
#define Mid(x,y) ((x+y)>>1)
struct nd 
{
    int zero, one, two, prop;
};
vector<nd>sg_tree;
void update(int index, int val, int node = 1, int start = 1, int end = n)
{
    sg_tree[node] = (sg_tree[node] + val);
    if(start == end) return;
    index<=Mid(start, end)? update(index, val, Left(node), start, Mid(start, end)) : update(index, val, Right(node), Mid(start, end)+1, end);
}
long long query(int l, int r, int node = 1, int start=1, int end = n)
{
    if(r<start || end<l)    return 0;
    if(start>=l && end <= r) return sg_tree[node];
    return (sum(l, r, Left(node), start, Mid(start, end))+sum(l, r, Right(node), Mid(start, end)+1, end));
}
int  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++tc << ":\n";
        int q;
        cin >> n >> q;
        sg_tree = vector<nd>(4*n, 0);
    }

    return 0;
}