#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int cunt = 0, orr=0;
    for(int i = 0; i<2; i++)
        for(int j = 0; j<2; j++)
        {
            int n;
            cin >> n;
            if(n)
                cunt ++;
            orr|=n;
        }
    cout << (cunt==4?2:(orr?1:0)) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

