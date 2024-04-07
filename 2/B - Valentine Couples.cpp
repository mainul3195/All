#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for(auto &i: a)
            cin >> i;
        for(auto &i: b)
            cin >> i;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long mx = -1;
        for(int i=0; i<n; i++)
            mx = max(a[i]+b[n-i-1], mx);
        cout << mx << "\n";
    }
    return 0;
}