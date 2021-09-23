#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int start=0;
    int end=s.size()-1;
    int l=s.size();
    while(l>2 && s.substr(start, 3)=="WUB")
        start+=3, l-=2;
    while(l>2 && s.substr(end-2, 3)=="WUB")
        end-=3, l-=3;
    bool done=0;
    for(int i=start; i<=end; )
    {
        if(i<=end - 2)
        {
            if(s.substr(i, 3)=="WUB")
            {
                if(!done)
                    cout << " ";
                i+=3;
                done = 1;
            }
            else
            {
                done = 0;
                cout << s[i++];
            }
        }
        else 
            cout << s[i++];
    }
    return 0;
}