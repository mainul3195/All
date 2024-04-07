#include<bits/stdc++.h>
using namespace std;
long long n, x;
vector<vector<long long>>v;
long long cnt = 0;
void solve(int i = 0, long long product = 1)
{
    if( i==n && product == x)
    {
        cnt ++;
        return;
    }
    if(product>x || i==n)
        return;
    for(auto j: v[i])
    {
        long long req = x/product + 2;
        if(j<req) solve(i+1, product*j);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x;
    v = vector<vector<long long>>(n, vector<long long> ());
    for(int i = 0; i<n; i++)
    {
        int l;
        cin >> l;
        while(l--)
        {
            long long j;
            cin >> j;
            v[i].push_back(j);
        }
    }

    solve();
    cout << cnt << "\n";
    return 0;
}