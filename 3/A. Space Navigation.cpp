#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
void solve()
{
    ll x, y;
    string s;
    cin >> x >> y >> s;
    ll cu=0, cd=0, cl=0, cr=0;
    for(auto i:s)
    {
        if(i=='U')
            cu++;
        else if(i=='D')
            cd++;
        else if(i=='L')
            cl++;
        else 
            cr++;
    }
    //cout << x << " " << y << " " << cu << " " << cd << " " << cl << " " << cr << "\n"; 
    if(((x>=0 && x<=cr) || (x<0 && (-x)<=cl)) && ((y>=0 && y<=cu) || (y<0 && (-y)<=cd)))
        cout << "YES\n";
    else 
        cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}