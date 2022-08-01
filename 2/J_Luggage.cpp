#include<bits/stdc++.h>
using namespace std;
vector<int>nm;
vector<vector<int>> dp;
int sum ;
bool possible(int i, int tot)
{
    if(tot == sum/2) return 1;
    if(tot > sum/2 || i==nm.size()) return 0;
    if(~dp[i][tot]) return dp[i][tot];
    return dp[i][tot] = possible(i+1, tot) | possible(i+1, tot+nm[i]);
}
int main()
{
    int t;
    cin >> t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin , s);
        stringstream st(s);
        int a;
        nm.clear();
        while( st >> a)
            nm.push_back(a);
        sum = 0;
        for(auto i: nm)
            sum += i;
        dp = vector<vector<int>> (nm.size()+1, vector<int> (sum+5, -1));
        if(sum%2 || !possible(0, 0))
            cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}