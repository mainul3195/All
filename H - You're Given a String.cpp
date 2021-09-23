#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int i=s.size()-1;
    cout << s << "\n";
    while(i)
    {
        set<string> st;
        for(j=0; j+i<=s.size; j++)
            st.insert(s.substr(j, i));
        cout << i << " " << st.size() << "\n";
        if(st.size() != s.size()-i+1)
            break;
        
        i--;
    }
    cout << i << "\n";
    return 0;
}