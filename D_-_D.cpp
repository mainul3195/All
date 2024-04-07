#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<long long> st;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        st.insert(x);
    }
    if (st.size() == 1)
    {
        cout << *st.begin() << "\n";
        return;
    }
    auto it = st.begin();
    long long frst = *it;
    it++;
    long long snd = *it;
    if (frst == 1)
    {
        cout << "1\n";
        return;
    }
    bool ok = (snd / 2 >= frst);
    if (ok)
    {
        cout << frst << "\n";
        return;
    }
    cout << frst / 2 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}