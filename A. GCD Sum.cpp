#include<bits/stdc++.h>
using namespace std;
long long sod(long long n)
{
    int dig = 0;
    while(n)
    {
        dig+=n%10;
        n/=10;
    }
    return dig;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        for(long long i=n; i<n+101; i++)
        {
            if(__gcd(i, sod(i))>1)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}