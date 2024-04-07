#include<bits/stdc++.h>
using namespace std;
long long etf(long long n)
{
    long long ans = n;
    for(long long i = 2; i*i<=n; i++)
    {
        if(n%i==0)
            ans -= ans/i;
        while(n%i ==0)
            n/=i;
    }
    if(n>1)
        ans -= ans/n;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long a, b;
    cin >> a >> b;
    for(long long i = a; i<=b; i++)
        cout << etf(i) << "\n";
    return 0;
}