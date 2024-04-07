#include <bits/stdc++.h>
using namespace std;
vector<int> grundy(1000006, -1);
int find_grundy(int n)
{
    if (n == 1 || n == 2)
        return 0;
    if (~grundy[n])
        return grundy[n];
    int x = 0, lim = (n + 1) / 2;
    set<int> st;
    for (int i = 1; i < lim; i++)
        st.insert(find_grundy(i) ^ find_grundy(n - i));
    int i = 0;
    while (st.size() && *st.begin() == i)
    {
        st.erase(st.begin());
        i++;
    }
    return grundy[n] = i;
}
void solve()
{
    int n;
    cin >> n;
    if (find_grundy(n))
        cout << "first\n";
    else
        cout << "second\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    find_grundy(10000);
    int t;
    // cin >> t;
    // while (t--)
    //     solve();
    return 0;
}