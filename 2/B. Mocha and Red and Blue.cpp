#include<bits/stdc++.h>
using namespace std;
int n;
string s;
void lconf(int i, char c)
{
    if(i==n)
        return;
    if(s[i] != '?')
        return;
    s[i] = c=='R'? 'B': 'R';
    lconf(i-1, s[i]);
    return;
}
void rconf(int i, char c)
{
    if(i<0)
        return;
    if(s[i] != '?')
        return;
    s[i] = c=='R'? 'B': 'R';
    rconf(i+1, s[i]);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        bool ok = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != '?')
            {
                ok = 1;
                lconf(i-1, s[i]);
                rconf(i+1,s[i]);
            }
        }
        if(ok)
            cout << s << "\n";
        else
            for(int i=0; i<n; i++)
                cout << (i%2? 'R': 'B') << (i==n-1? "\n" : "");
    }
    return 0;
}