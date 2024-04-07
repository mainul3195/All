#include <bits/stdc++.h>
using namespace std;
int present[1000006];
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
        present[i] ++;
    }
    if(n==1)
    {
        cout << "1\n";
        return;
    }
    if(present[1])
    {
        if(present[1]>1)
            cout << "0\n";
        else cout << "1\n";
        return;
    }
    int count = 0;
    for (auto x : v)
    {
        if(present[x]>1)
            continue;
        bool ok = 1;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0 && (present[i] || present[x / i]))
            {
                ok = 0;
                break;
            }
        if (ok)
            count++;
    }
    cout << count << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}