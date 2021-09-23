#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> num(n);
    for(auto &i: num)
        cin >> i;
    long long ans = 0;
    for(int i=1; i<n; i++)
        if(num[i-1]>=num[i])
        {
            long long temp =  (num[i-1]-num[i])/k + 1;
            ans += temp;
            num[i] += temp*k;
        }
    cout << ans << "\n";
    return 0;
}