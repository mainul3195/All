#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(t--)
    {
        getline(cin, s);
        if(s.size()<5)
            cout << s << "\n";
        else
        {
            for(int i=0; i<s.size()-4; i++)
            {
                if(s.substr(i, 5)=="party")
                {
                    s[i+2]='w';
                    s[i+3]='r';
                    s[i+4]='i';
                    i+=4;
                }
            }
            cout << s << "\n";
        }
    }
    return 0;
}