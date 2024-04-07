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
    string s;
    cin >> s;
    bool first = 1;
    for(auto i: s)
    {
        if(first)
        {
            if(i=='a')
                cout << 'b';
            else
                cout << 'a';
            first=0;
        }
        else
        {
            if(i=='z')
                cout << 'y';
            else
                cout << 'z';
            first= 1;
        }
    }
    cout << "\n";
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