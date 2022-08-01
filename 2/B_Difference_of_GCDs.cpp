#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, l, r;
        cin >> n >> l >> r;
        long long lowr = 0;
        for(long long i = 1; i<=n; i++)
        {
            long long a = (l+i-1)/i*i;
            lowr = max(lowr, a);
        }
        if(lowr>r)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(long long i = 1; i<=n; i++)
            {
                long long a = (l+i-1)/i*i;
                cout << a << " ";
            }
            cout << "\n";
        }
    }
}