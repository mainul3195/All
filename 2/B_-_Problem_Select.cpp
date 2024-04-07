#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    vector<int> v;
    while (n--)
    {
        cin >> s;
        string nm;
        while (s.back() != '/')
        {
            nm = s.back() + nm;
            s.pop_back();
        }
        v.push_back(stoi(nm));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++)
        cout << v[i] << " \n"[i == k - 1];
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