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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int last_same = 0;
    for(int i=n-1; i>=0 && a[i]==b[i]; i--, last_same++);
    int diff_1 = 0, diff_0 = 0;
    int same_0 = 0, same_1 = 0;
    n-=last_same;
    bool ok=1;
    for(int i=0; i<n;i++)
    {
        diff_1 = 0, diff_0 = 0;
        same_0 = same_1 = 0;
        while(i<n && a[i]!=b[i])
        {
            if(a[i]=='0')
                diff_0++;
            else 
                diff_1++;
            i++;
        }
        while(i<n && a[i]==b[i])
        {
            if(a[i]=='0')
                same_0++;
            else 
                same_1++;
            i++;
        }
        i--;
        if(diff_0 != diff_1 || same_1 != same_0)
        {
            ok=0;
            break;
        }
    }
    if(ok)
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