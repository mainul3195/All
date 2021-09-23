#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
bool palindrome(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if(s == s1)
        return 0;
    return 1;
}
void solve()
{
    string s;
    cin >> s;
    int count[26]={0};
    for(auto i: s)
        count [(int)(i-'a')]++;
    if(count[0]==s.size())
        cout << "NO\n";
    else 
    {
        cout << "YES\n";
        string temp = "a"+s;
        string temp2 = s + "a";
        if(palindrome(temp))
            cout << temp << "\n";
        else
        {
            cout << temp2 << "\n";
        }
        
    }
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