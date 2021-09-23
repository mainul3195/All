#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int len = min((int)a.size(), (int)b.size());
        bool done = 0;
        for( ; len>0; len--)
        {
            for(int i=0; i+len<=a.size(); i++)
            {
                for(int j=0; j+len <= b.size(); j++)
                {
                    if(a.substr(i, len) == b.substr(j, len))
                    {
                        done = 1;
                        break;
                    }
                }
                if(done)
                    break;
            }
            if(done)
                break;
        }
        cout << a.size()+b.size()-2*len << "\n";
    }
    return 0;
}