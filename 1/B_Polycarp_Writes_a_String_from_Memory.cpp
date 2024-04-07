#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        set<int>st;
        int ans = 0;
        for(auto c: s)
        {
            if(st.find(c) == st.end() && st.size()==3)
            {
                ans++;
                st.clear();
            }
            st.insert(c);
        }
        cout << ans + !st.empty() << "\n";
    }
    return 0;
}