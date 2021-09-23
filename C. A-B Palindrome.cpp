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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool ok= 1;
    int n = s.size();
    int lim = n/2;
    for(int i=0, j = n-1; i<lim; i++, j--)
    {
        if(s[i]=='?' && s[j] == '?') continue;
        if(s[i]!='?' && s[j] != '?' && s[i] != s[j])
        {
            ok = 0;
            break;
        }
        if(s[i] != '?')
            s[j]=s[i];
        else if(s[j] != '?')
            s[i]=s[j];
        if(s[i]=='0')
            a-=2;
        else 
            b-=2;
    }
    if(n%2 && s[n/2] != '?')
    {
        if(s[n/2]=='0')
            a--;
        else 
            b--;
    }
    if(a<0 || b<0)
        ok = 0;
    for(int i=0, j = n-1; ok && i<lim; i++, j--)
    {
        if(s[i]!='?' && s[j] != '?') continue;
        if(a<2 && b<2)
        {
            ok = 0;
            break;
        }
        if(s[i]=='?' && s[j] == '?')
        {
            if(a>1)
            {
                a-=2;
                s[i]=s[j]='0';
            }
            else if(b>1)
            {
                b-=2;
                s[i]=s[j]='1';
            }
        }
    }
    if(n%2 && ok)
    {
        if(s[n/2] == '?')
        {
            if(a==1 && !b)
                s[n/2]='0';
            else if(b==1 && !a)
                s[n/2] = '1';
            else 
                ok = 0;
        }
    }
    if(ok)
        cout << s << "\n";
    else 
        cout << "-1\n";
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