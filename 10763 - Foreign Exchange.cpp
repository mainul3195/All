#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n and n)
    {
        map<int, int> in, out;
        set<int> st;
        for(int i=0; i<n; i++)
        {
            int j,k;
            cin >> j >> k;
            in[k]++;
            out[j]++;
            st.insert(j);
            st.insert(k);
        }
        bool ok=1;
        for(auto i:st)
        {
            if(in[i]!=out[i])
            {
                ok=0;
                break;
            }
        }
        if(ok)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}