#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
vector<int> dist, avail, cur;
long long n, can_put, x, q, k;
int solve(int i, long long l)
{
    // cout << "*******\n"<< i << "\n";
    // for(int j=0; j<n; j++)
    //     cout <<  dist[j] << " " << avail[j] << " " << cur[j] << "\n";
    if(i==-1)
        return -1;
    can_put = dist[i]-cur[i];
    //cout << can_put  << " " << l<< "\n****\n";
    if(can_put <= l)
    {
        ans+=can_put*(i-x);
        cur[i] = dist[i];
        avail[i] = solve(avail[i+1], l-can_put);
    }
    else
    {
        ans += l*(i-x);
        cur[i] += l;
        return i;
    }
    return avail[i];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    dist.assign(n,0);
    avail.assign(n+1, -1);
    cur.assign(n, 0);
    for(auto &i: dist)
        cin >> i;
    for(int i=0; i<n; i++)
        avail[i]=i;
    cin >> q;
    while(q--)
    {
        cin >> x >> k;
        x--;
        avail[x] = solve(avail[x], k);
        cout << ans << "\n";
        ans = 0;
    }
    return 0;
}
