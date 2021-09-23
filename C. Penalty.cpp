#include<bits/stdc++.h>
using namespace std;
string s;
bool end(int i, int f, int s)
{
    int avail = 9-i;
    int fa = avail/2;
    int sa = (avail+1)/2;
    if(f+fa<s || s+sa<f)
        return true;
    return false;
}
int solve(int i, int frst, int scnd)
{
    if(i==9) return 1;
    int temp1 = 11, temp2 = 11;
    if(s[i]=='0' || s[i]=='?')
    {
        if(end(i, frst, scnd)) return 1;
        else temp1 = solve(i+1, frst, scnd);
    }
    if(s[i]=='1' || s[i]=='?') 
    {
        i%2? scnd++: frst++;
        if(end(i, frst, scnd)) return 1;
        else temp2 = solve(i+1, frst, scnd);
    }
    return 1+min(temp1, temp2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << solve(0, 0, 0) << "\n";
    }
    return 0;
}