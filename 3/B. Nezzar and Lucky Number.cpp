#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int q,d;
        cin >> q >> d;
        while(q--)
        {
            int a;
            cin >> a;
            if(a>=10*d)
            {
                cout << "Yes\n";
                continue;
            }
            bool ok=0;
            for(int i=1; i<=9; i++)
            {
                if(((d*i)%10 == a%10) && ((d*i)/10 <= a/10))
                {
                    ok=1;
                    break;
                }
            }
            if(ok)
                cout << "Yes\n";
            else 
                cout << "No\n";
        }
    }
    return 0;
}