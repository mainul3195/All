#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n, s;
    cin >> n  >> s;
    vector<long long> v(n);
    for(auto &i: v)
        cin >> i;
    long long ans = 0, csum = 0;
    unordered_map<long long, long long>found;
    for(auto i: v)
    {
        csum += i;
        if(csum == s)
            ans ++;
        if(found.find(csum-s)!=found.end())
            ans += found[csum-s];
        found[csum]++;
    }
    cout << ans << "\n";
    return 0;
}