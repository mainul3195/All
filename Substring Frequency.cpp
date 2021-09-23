#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while (t--)
    {
        int ans=0;
        string s1, s2;
        cin >> s1 >> s2;
        int len=s2.size();
        if(len<=s1.size())
            for(int i=0; i+len<=s1.size(); i++)
                if(!s1.compare(i, len, s2))
                    ans++;
        cout << "Case " << ++tc << ": " << ans << "\n";
    }
    return 0;
}