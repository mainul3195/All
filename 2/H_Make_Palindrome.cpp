#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp, dir;
vector<string>before, after;
string s;
int okdone(int i, int j)
{
    if(i>=j) return 0;
    if(~dp[i][j]) return dp[i][j];
    int ans;
    if(s[i]==s[j])
    {
        ans = okdone(i+1, j-1);
        dir[i][j] = 1;
    }
    else
    {
        int t1 = okdone(i+1, j);
        int t2 = okdone(i, j-1);
        if(t1<t2)
        {
            ans = t1;
            dir[i][j] = 2;
        }
        else
        {
            ans = t2;
            dir[i][j] = 3;
        }
        ans ++;
    }
    
    return dp[i][j] = ans;
}
void solve()
{
    while(cin >> s)
    {
        before = vector<string>(s.size()+5);
        after = vector<string>(s.size()+5);
        dp = vector<vector<int>> (s.size()+2, vector<int> (s.size()+2, -1));
        dir = vector<vector<int>> (s.size()+2, vector<int> (s.size()+2, -1));
        cout << okdone(0, s.size()-1) << " ";
        int i,j;
        for(i=0, j = s.size()-1; i<j; )
        {
            if(dir[i][j]==1) i++, j--;
            else if(dir[i][j]==2) after[j] = s[i++] + after[j];
            else before[i] += s[j--];
        }
        for(int i=0; i<s.size(); i++)
        {
            if(before[i].size()) cout << before[i];
            cout << s[i];
            if(after[i].size()) cout << after[i];
        }
        cout << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc = 0;
    // cin >> t;
    while(t--)
    {
        solve(); 
    }
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/
