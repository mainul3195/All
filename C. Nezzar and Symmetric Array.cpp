#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        set<long long> st;
        bool ok=1;
        for(int i=0; i<2*n; i++)
        {
            long long j;
            cin >> j;
            if(j%2)
                ok=0;
            st.insert(j);
        }
        int sz=st.size();
        if(sz!=n)
            ok=0;
        if(ok)
        {
            long long minus=0;
            while(sz)
            {
                auto it = st.end();
                long long last= *(--it);
                long long numerator=last-minus;
                long long denominator=2*sz;
                if(numerator%denominator || numerator/denominator<=0)
                {
                    ok=0;
                    break;
                }
                minus += numerator/denominator*2;
                sz--;
                st.erase(it);
            }
        }
        if(ok)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}