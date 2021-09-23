#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> v;
struct nd{long long pre, suf, sum, ans;};
nd combine(nd left, nd right)
{
    nd res;
    res.sum = left.sum + right.sum;
    res.pre = max(left.pre, left.sum+right.pre);
    res.suf = max(right.suf, right.sum + left.suf);
    res.ans = max(max(left.ans, right.ans), left.suf+right.pre);
    return res;
}
#define Left(x) (x<<1)
#define Right(x) (Left(x)+1)
#define Mid(x,y) ((x+y)>>1)
vector<nd>sg_tree;
nd make(long long n)
{
    nd res;
    res.ans = res.pre = res.suf = res.sum = n;
    return res;
}
void init(int node = 1, int start = 1, int end = n)
{
    if(start == end)
    {
        sg_tree[node] = make(v[start - 1]);
        return;
    }
    init(Left(node), start, Mid(start, end));
    init(Right(node), Mid(start, end)+1, end);
    sg_tree[node] =  combine(sg_tree[Left(node)], sg_tree[Right(node)]);
    return;
}
nd query(int l, int r, int node = 1, int start=1, int end = n)
{
    if(r<start || end<l)    return make(0);
    if(start>=l && end <= r) return sg_tree[node];
    return combine(query(l, r, Left(node), start, Mid(start, end)),query(l, r, Right(node), Mid(start, end)+1, end));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    v = vector<long long>(n);
    for(auto &i: v)
        cin >> i;
    sg_tree = vector<nd>(4*n);
    init();
    cin >> m;
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        nd temp = query(l,r);
        cout << temp.ans << "\n";
    }
    return 0;
}