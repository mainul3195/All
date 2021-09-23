#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int>v, sg_tree;
void init(int node, int start, int end)
{
    if(start == end)
    {
        sg_tree[node] = v[start - 1];
        return;
    }
    init(node<<1, start, (start+end)>>1);
    init((node<<1)+1, ((start+end)>>1)+1, end);
    sg_tree[node] = min(sg_tree[(node<<1)] , sg_tree[((node<<1) + 1)]);
    return;
}
int query(int node, int l, int r, int start, int end)
{
    if(r<start || end<l) return 10000000;
    if(start>=l && end <= r) return sg_tree[node];
    return min(query((node<<1), l, r, start,((start+end)>>1)), query(((node<<1) + 1), l, r,(((start+end)>>1) + 1) , end));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++tc << ":\n";
        cin >> n >> q;
        v = vector<int>(n);
        sg_tree = vector<int>(4*n);
        for(auto &i: v)
            cin >> i;
        init(1,1,n);
        while(q--)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1,l,r,1,n) << "\n";
        }
    }
    return 0;
}