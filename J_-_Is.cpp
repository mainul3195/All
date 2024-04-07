#include <bits/stdc++.h>
using namespace std;

vector<int> par;
int n, ans;
struct block
{
    int l, r, up, id;
    // void print()
    // {
    //     cout << "l = " << l << "\tr = " << r << "\tup = " << up << "\tid = " << id << "\n";
    //     return;
    // }
};
map<int, vector<block>> height;
int getpar(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
bool cmp1(block &a, block &b)
{
    return (a.r < b.r || (a.r == b.r && a.up < b.up));
}
bool cmp2(block &a, block &b)
{
    return a.l > b.l || (a.l == b.l && a.up < b.up);
}
void join(int u, int v)
{
    int pu = getpar(u);
    int pv = getpar(v);
    if (pu != pv)
    {
        // cout << u << " " << v << " " << pu << " " << pv << "\n";
        ans--;
        par[pv] = pu;
    }
}
void solve()
{
    cin >> n;
    par = vector<int>(n);
    for (int i = 0; i < n; i++)
        par[i] = i;
    ans = n;
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        height[y1].push_back({x1, x2, 0, i});
        height[y2].push_back({x1, x2, 1, i});
    }
    vector<block> down;
    for (auto [i, v] : height)
    {
        down.clear();
        sort(v.begin(), v.end(), cmp1);
        // cout << "up:\n";
        // cout << i << " -> \n";
        // for (auto k : v)
        //     k.print();
        for (auto [l, r, up, id] : v)
        {
            if (up)
            {
                for (int j = down.size() - 1; j >= 0; j--)
                {
                    if (down[j].r <= l)
                        break;
                    // if (id == 3 && down[j].id == 1)
                    // {
                    //     cout << "from here 1\n";
                    // }
                    join(id, down[j].id);
                }
            }
            else
                down.push_back({l, r, up, id});
        }

        down.clear();
        sort(v.begin(), v.end(), cmp2);
        // cout << "down:\n";
        // cout << i << " -> \n";
        // for (auto k : v)
        //     k.print();
        for (auto [l, r, up, id] : v)
        {
            if (up)
            {
                for (int j = down.size() - 1; j >= 0; j--)
                {
                    if (down[j].l >= r)
                        break;
                    // if (id == 3 && down[j].id == 1)
                    // {
                    //     cout << r << " from here 2\n";
                    //     cout << down.size() << "\n";
                    //     down[j].print();
                    // }
                    join(id, down[j].id);
                }
            }
            else
                down.push_back({l, r, up, id});
        }
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}