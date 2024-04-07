#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "! 0 1" << endl;
        return;
    }
    int highest = 0;
    for (int i = 1; i < n; i++)
    {
        cout << "? " << highest << " " << highest << " " << i << " " << i << endl;
        char c;
        cin >> c;
        if (c == '<')
            highest = i;
    }
    vector<int> v;
    int optimal = highest;
    for (int i = 0; i < n; i++)
        if (i != highest)
        {
            cout << "? " << highest << " " << optimal << " " << highest << " " << i << endl;
            char c;
            cin >> c;
            if (c == '<')
            {
                v.clear();
                v.push_back(i);
                optimal = i;
            }
            else if (c == '=')
                v.push_back(i);
        }
    int low = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        cout << "? " << low << " " << low << " " << v[i] << " " << v[i] << endl;
        char c;
        cin >> c;
        if (c == '>')
            low = v[i];
    }
    cout << "! " << low << " " << highest << endl;
    return;
}
int32_t main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}