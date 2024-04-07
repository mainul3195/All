#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> st;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        if (!u)
            zero += 1;
        st.insert(u);
    }
    if (zero)
        cout << n - zero << "\n";
    else if (st.size() == n)
        cout << n + 1 << "\n";
    else
        cout << n << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}