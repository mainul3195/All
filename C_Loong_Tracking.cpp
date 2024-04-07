#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int val, x, y;
    bool operator<(const nd &a) const
    {
        return val < a.val;
    }
};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<nd, null_type, less<nd>, rb_tree_tag, tree_order_statistics_node_update>
int n, q;
void solve()
{
    cin >> n >> q;
    ordered_set st;
    int start = 1;
    for (int i = 1; i <= n; i++)
        st.insert({i, i, 0});
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            char c;
            cin >> c;
            auto [v, x, y] = *(st.find_by_order(0));
            auto it = st.find_by_order(n - 1);
            start--;
            st.erase(it);
            if (c == 'U')
                st.insert({start, x, y + 1});
            else if (c == 'D')
                st.insert({start, x, y - 1});
            else if (c == 'L')
                st.insert({start, x - 1, y});
            else
                st.insert({start, x + 1, y});
        }
        else
        {
            int k;
            cin >> k;
            k--;
            auto [v, x, y] = *(st.find_by_order(k));
            cout << x << " " << y << "\n";
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}