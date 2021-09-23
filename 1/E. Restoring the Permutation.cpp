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
        set<int> st;
        vector<int>mn(n), mx(n);
        for(int i=0; i<n; i++)
        {
            cin >> mn[i];
            mx[i]=mn[i];
            st.insert(mn[i]);
        }
        int s;
        s=mn[0];
        for(int i=0,j=1; i<n-1; i++)
        {
            if(s==mn[i+1])
            {
                while(st.find(j)!=st.end())
                    j++;
                mn[i+1] = j++;
            }
            else s=mn[i+1];
        }
        for(int i=1; i<=n; i++)
            st.insert(i);
        s=mx[0];
        for(int i=0; i<n-1; i++)
        {
            if(s==mx[i+1])
            {
                auto it = st.find(s);
                it --;
                mx[i+1]=*it;
                st.erase(it);
            }
            else
            {
                st.erase(s);
                s=mx[i+1];
            }
            
        }
        for(int i=0; i<n; i++)
            cout << mn[i] << " \n"[i==n-1];
        for(int i=0; i<n; i++)
            cout << mx[i] << " \n"[i==n-1];
    }
    return 0;
}