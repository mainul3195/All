#include<bits/stdc++.h>
using namespace std;
int val(int v, int t)
{
    for(int i = 0; i<t; i++)
    {
        int t = 0;
        while(v)
        {
            t+=v%10;
            v/=10;
        }
        v = t;
        if(v<10)
            return v;
    }
    return v;
}

vector<int>vec;
vector<int> segment_tree;
int n, q;
void update(int l, int r, int node = 1, int start = 1, int end = n)
{
    if(start>r || end<l)
        return;
    if(start>=l && end <= r)
    {
        segment_tree[node]++;
        return;
    }
    int mid = (start+end)/2;
    update(l, r, 2*node, start, mid);
    update(l, r, 2*node+1, mid+1, end);
    return;
}
int query(int ind, int node = 1, int start = 1, int end = n)
{
    if(start == end)
        return segment_tree[node];
    int mid = (start+end)/2;
    return segment_tree[node]+(ind<=mid?query(ind, 2*node, start, mid): query(ind, 2*node+1, mid+1, end));
}
void solve()
{
    cin >> n >> q;
    vec = vector<int>(n);
    for(auto &i: vec)
        cin >> i;
    segment_tree  =  vector<int>(4*n, 0);
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int l, r;
            cin >> l >> r;
            update(l, r);
        }
        else
        {
            int ind;
            cin >> ind;
            cout << val(vec[ind-1], query(ind)) << "\n";
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}