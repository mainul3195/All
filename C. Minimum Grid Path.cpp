#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<long long> cost(n);
    for(auto &i: cost)
        cin >> i;
    long long even_sum=cost[0], even_min=cost[0], odd_sum = cost[1], odd_min = cost[1], even_count = 0, odd_count = 0;
    long long ans = (even_sum - even_min + even_min*(n-even_count)) + ( odd_sum - odd_min + odd_min*(n-odd_count));
    for(int i=2; i<n; i++)
    {
        if(i%2)
        {
            odd_count ++;
            odd_sum += cost[i];
            odd_min = min(odd_min, cost[i]);
        }
        else
        {
            even_count++;
            even_sum += cost[i];
            even_min = min(even_min, cost[i]);
        }
        ans = min(ans, (even_sum - even_min + even_min*(n-even_count)) + ( odd_sum - odd_min + odd_min*(n-odd_count)));
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}