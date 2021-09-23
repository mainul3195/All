#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        long long s;
        cin >> s;
        long long x, y;
        long long tmp = sqrt(s-1) + 1;
        long long tot = tmp*tmp - (tmp-1)*(tmp-1);
        if(tmp & 1)
        {
            if(s-(tmp-1)*(tmp-1)<=(tot+1)/2)
            {
                x = tmp;
                y = s-(tmp-1)*(tmp-1);
            }
            else
            {
                y=tmp;
                x=tmp*tmp - s +1;
            }
        }
        else
        {
            if(s-(tmp-1)*(tmp-1)<=(tot+1)/2)
            {
                y = tmp;
                x = s-(tmp-1)*(tmp-1);
            }
            else
            {
                x=tmp;
                y=tmp*tmp - s +1;
            }
        }
        cout << "Case " << ++tc << ": " << x << " " << y << "\n";
    }
    return 0;
}