#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >>n;
    vector<long long> v(n);
    for(auto &i: v)
        cin >> i;
    long long ans = 0;
    for(int k = 0; k<=30; k++)
    {
        long long prev1 = 0, prev0 = 0;
        for(int i = 0; i<n; i++)
        {
            if(v[i]&(1<<k) == 1)
            
        }
    }
    return 0;
}