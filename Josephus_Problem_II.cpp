#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    int n, k;
    cin >> n >> k;
    ordered_set st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    int pos = k % n;
    while (st.size() > 1)
    {
        auto it = st.find_by_order(pos);
        cout << *it << " ";
        st.erase(it);
        pos = (pos + k) % st.size();
    }
    cout << *st.find_by_order(0) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}