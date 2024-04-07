#include <bits/stdc++.h>
using namespace std;

struct heap
{
    vector<int> tree;
    heap()
    {
        tree.push_back(-1);
    }
    void insert(int u)
    {
        tree.push_back(u);
        int cur = tree.size() - 1;
        while (cur / 2 >= 1 && tree[cur] < tree[cur / 2])
        {
            swap(tree[cur], tree[cur / 2]);
            cur >>= 1;
        }
        int k = 0;
    }
    void heapify(int ind)
    {
        int tmp = ind;
        if (tmp * 2 + 1 < tree.size() && tree[tmp * 2 + 1] < tree[tmp] && tree[tmp * 2] >= tree[tmp * 2 + 1])
            tmp = tmp * 2 + 1;
        else if (tmp * 2 < tree.size() && tree[tmp * 2] < tree[tmp])
            tmp = tmp * 2;
        if (ind != tmp)
        {
            swap(tree[ind], tree[tmp]);
            heapify(tmp);
        }
    }
    int pop()
    {
        int tmp = tree[1];
        swap(tree[1], tree[tree.size() - 1]);
        tree.pop_back();
        heapify(1);
        return tmp;
    }
    bool empty()
    {
        return tree.size() == 1;
    }
};
void heapsort(vector<int> &v, int l, int r)
{
    heap H = heap();
    for (int i = l; i <= r; i++)
        H.insert(v[i]);
    v.clear();
    while (!H.empty())
        v.push_back(H.pop());
    cout << "\n";
    return;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    heapsort(v, 0, n - 1);
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}