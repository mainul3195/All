#include <bits/stdc++.h>
using namespace std;
struct pr
{
    int a, b;
    bool operator<(const pr &x) const
    {
        return (a + b) > (x.a + x.b) || ((a + b) == (x.a + x.b) && a < x.a) || ((a + b) == (x.a + x.b) && a == x.a && b < x.b);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("domino.in", "r", stdin);
    // freopen("domino.out", "w", stdout);
    int n, r;
    cin >> n >> r;
    multiset<pr> st;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        st.insert({a, b});
        tot += a + b;
    }
    r <<= 1;
    int frst, lst;
    for (int i = 0; i < r; i++)
    {
        if (!i)
            cin >> frst;
        else
            cin >> lst;
    }
    int remaining = tot;
    if (st.find({frst, frst}) != st.end())
    {
        st.erase(st.find({frst, frst}));
        if (st.find({lst, lst}) != st.end())
        {
            if (n == 2)
            {
                cout << "-1\n";
                return 0;
            }
            remaining = tot - 2 * (frst + lst);
        }
        st.insert({frst, frst});
    }
    for (auto [a, b] : st)
        if (a == frst || b == frst || a == lst || b == lst)
        {
            if (n == 1)
            {
                cout << "-1\n";
                return 0;
            }
            remaining = min(remaining, tot - (a + b));
        }
    cout << remaining << "\n";
    return 0;
}


