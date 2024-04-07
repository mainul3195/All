#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> st;
    for (int i = 0; i < n - 1; i++)
        if (v[i] != v[n - 1])
            st.push_back(i);
    int count = 0;
    while (st.size())
    {
        int ind = st.back();
        int done = n - ind - 1;
        ind = ind - done + 1;
        while (st.size() && st.back() >= ind)
            st.pop_back();
        count++;
    }
    cout << count << "\n";
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