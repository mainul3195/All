#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> s(n);
        for(int i=0; i<n; i++)
            cin >> s[i];
        int same;
        int mn=1;
        for(int i=1; i<n; i++)
        {
            same =1;
            while(i<n && s[i]==s[i-1])
            {
                same++;
                i++;
            }
            mn=max(same, mn);
        }
        cout << mn << "\n";
    }
    return 0;
}