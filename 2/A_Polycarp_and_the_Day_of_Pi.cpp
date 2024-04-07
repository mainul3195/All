#include<bits/stdc++.h>
using namespace std;
string pi = "314159265358979323846264338327";
void solve()
{
    int cnt = 0;
    string s;
    cin >> s;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == pi[i])
            cnt++;
        else break;
    }
    cout << cnt << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}