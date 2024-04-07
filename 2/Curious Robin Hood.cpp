#include<bits/stdc++.h>
using namespace std;
int n, q;           
#define Left(x) (node<<1)
#define Right(x) (Left(x)+1)
#define Mid(x,y) ((x+y)>>1)
vector<long long> sg_tree, num;
long long init(int node = 1, int start = 1, int end = n)
{
    if(start == end)
        return sg_tree[node] = num[start - 1];
    return sg_tree[node] = init(Left(node), start, Mid(start, end)) + init(Right(node), Mid(start, end)+1, end);
}
long long donate(int index, int node = 1, int start = 1, int end = n)
{
    if(start == end)
    {
        long long t = sg_tree[node];
        sg_tree[node] = 0;
        return t;
    }
    long long temp = ((index<=Mid(start, end)) ? donate(index, Left(node), start, Mid(start, end)):donate(index, Right(node), Mid(start, end)+1, end));
    sg_tree[node] -= temp;
    return temp;
}
long long sum(int l, int r, int node = 1, int start = 1, int end = n)
{
    if(r<start || end<l) return 0;
    if(start>=l && end <= r) return sg_tree[node];
    return sum(l, r, Left(node), start, Mid(start, end)) + sum(l, r, Right(node), Mid(start, end)+1, end);
}
void add(int index, int val, int node = 1, int start = 1, int end = n)
{
    sg_tree[node] += val;
    if(start == end) return;
    ((index<=Mid(start, end)) ? add(index, val, Left(node), start, Mid(start, end)):add(index, val, Right(node), Mid(start, end)+1, end));
    return;
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
        sg_tree = vector<long long> (4*n);
        num = vector<long long> (n);
        for(auto &i: num)
            cin >> i;
        init();
        while(q--)
        {

            int type, l, r;
            cin >> type;
            if(type == 1)
            {
                cin >> l;
                cout << donate(++l) << "\n";
            }
            else if(type == 2)
            {
                cin >> l >> r;
                add(++l, r);
            }
            else
            {
                cin >> l >> r;
                cout << sum(++l, ++r) << "\n";
            }
        }
    }
    return 0;
}