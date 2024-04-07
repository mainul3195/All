#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int>v(n+1, 0);
    cout << "2\n";
    for(int i = 1; i<=n; i++)
        if(!v[i])
        {
            for(int j = i; j<=n; j*=2)
            {
                cout << j << " ";
                v[j] = 1;
            }
        }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

