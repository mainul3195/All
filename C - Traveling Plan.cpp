#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n+2, 0);
    for(int i=1; i<=n; i++)
        cin >> v[i];
    long long tot=0;
    for(int i=0; i<=n; i++)
        tot += abs(v[i]-v[i+1]);
    for(int i=1; i<=n; i++)
        cout << tot - abs(v[i-1]-v[i]) - abs(v[i]-v[i+1]) + abs(v[i-1]-v[i+1]) << "\n";
    return 0;
}