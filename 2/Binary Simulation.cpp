#include<bits/stdc++.h>
using namespace std;
struct nd { int ones, prop;};
vector<nd>sg_tree;
string s;
void init(int node, int start, int end)
{
    if(start == end)
    {
        sg_tree[node].ones = s[start -1]-'0';
        return;
    }
    init((node<<1), start, ((start+end)>>1));
    init(((node<<1)+1), (((start+end)>>1)+1), end);
    return;
}
void update(int node, int l, int r, int start, int end)
{
    if(r<start || end<l) return;
    if(start>=l && end<=r)
    {
        sg_tree[node].prop ++ ;
        return;
    }
    update((node<<1), l, r, start, ((start+end)>>1));
    update(((node<<1)+1), l, r, (((start+end)>>1)+1), end);
    return;
}
int query(int node, int start, int end, int find, int cur = 0)
{
    cur += sg_tree[node].prop;
    if(start == end)
        return (sg_tree[node].ones + cur)%2;
    int mid = ((start+end)>>1);
    if(find<=mid) query((node<<1), start, mid, find, cur);
    else query(((node<<1)+1), mid+1, end, find, cur);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++tc << ":\n";
        cin >> s;
        sg_tree = vector<nd>(4*s.size());
        init(1,1,s.size());
        int q;
        cin >> q;
        while(q--)
        {
            char c;
            int l,r;
            cin >> c;
            if(c=='I')
            {
                cin >> l >> r;
                update(1, l, r, 1, s.size());
            }
            else
            {
                cin >> l;
                cout << query(1, 1, s.size(), l) << "\n";
            }
        }
    }
    return 0;
}