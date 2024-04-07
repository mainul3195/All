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
    int n, k;
    cin >> n >> k;
    for(int i=0; i<k-3; i++)
        cout << "1 ";
    n=n-k+3;
    if(n%2)
        cout << n/2 << " " << n/2 << " " << 1 << "\n";
    else
    {
        if(n%4)
            cout << n/2-1 << " " << n/2-1 << " " << 2 << "\n";
        else
        {
            cout << n/2 << " " << n/4 << " " << n/4 << "\n";
        }
        
    }
    return ;

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