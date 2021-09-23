#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int p, q;

        cin >> p >> q;
        if(p>q)
            p^=q^=p^=q;
        int ans = 0;
        while(p)
        {
            ans += q/p;
            int t = p;
            p=q%p;
            q=t;
        }
        cout << ans << "\n";
    }
    return 0;
}