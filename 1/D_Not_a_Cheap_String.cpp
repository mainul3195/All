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
        int ar[27] = {0};
        for(auto c: s)
            ar[c-'a'+1]++;
        int tot = 0;
        for(int i = 1; i<=26; i++)
            tot += i*ar[i];
        // cout << tot << "\n";
        int d;
        cin >> d;
        bool done = 0;
        for(int i = 26; !done && i>0; i--)
        {
            for(int j = ar[i]; j; j--)
            {
                if(tot>d)
                {
                    tot-=i;
                    ar[i]--;
                }
                else
                {
                    done = 1;
                    break;
                }
            }
        }
        // cout << tot << "\n";
        for(auto c: s)
        {
            int ch = c-'a'+1;
            if(ar[ch])
            {
                cout << c;
                ar[ch]--;
            }
        }
        cout << "\n";
    }
    return 0;
}