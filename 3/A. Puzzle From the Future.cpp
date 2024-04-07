#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char>v;
        v.push_back('1');
        for(int i=1; i<n; i++)
        {
            if((s[i-1]=='1'&&v[i-1]=='1'&&s[i]=='1')||(((v[i-1]=='0'&&s[i-1]=='1') ||(v[i-1]=='1' && s[i-1]=='0')) && s[i]=='0'))
                v.push_back('0');
            else 
                v.push_back('1');
        }
        for(auto i: v)
            cout << i;
        cout << "\n";
    }
    return 0;
}