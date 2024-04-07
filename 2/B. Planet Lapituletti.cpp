#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
set<int>invalid = {3,4,6,7,9};
int a, b;
bool valid(int h, int m)
{
    int temp1=h, temp2 = m, rh=0, rm=0, d1=0, d2=0;
    while(temp1)
    {
        d1++;
        int rem= temp1%10;
        if(rem==2)
            rem=5;
        else if(rem == 5)
            rem = 2;
        if(invalid.find(rem)!= invalid.end())
            return 0;
        temp1/=10;
        rm = rm*10 + rem;
    }
    while(temp2)
    {
        d2++;
        int rem= temp2%10;
        if(rem==2)
            rem=5;
        else if(rem == 5)
            rem = 2;
        if(invalid.find(rem)!= invalid.end())
            return 0;
        temp2/=10;
        rh = rh*10 + rem;
    }
    if(d1==1)
        rm*=10;
    if(d2==1)
        rh*=10;
    if(rh>=a || rm>=b)
        return 0;
    return 1;
}
void increase(int &sh, int &sm)
{
    int c=(++sm)/b;
    sm %= b;
    sh = (sh+c)%a;
    return;
}
void solve()
{
    int sh, sm;
    cin >> a >> b;
    char c;
    cin >> sh >> c >> sm;
    while(!valid(sh, sm))
    {
        increase(sh, sm);
   // printf("%02d:%02d\n", sh, sm);
    }
    printf("%02d:%02d\n", sh, sm);
    return;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}