#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    vector<int> zero(m, 0), one(m, 0);
    for(int i=0; i<n; i++)
    {
        cin >> s;
        for(int j=0; j<m; j++)
        {
            if(s[j]=='0')
                zero[j]++;
            else 
                one[j]++;
        }
    }
    // for(auto i: zero)
    //     cout << i << " ";
    // cout << "\n";
    for(auto i: one)
        cout << i << " ";
    cout << "\n";
    return 0;
}