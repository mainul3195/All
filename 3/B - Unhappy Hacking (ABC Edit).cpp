#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        if(s[i]=='B')
        {
            if(i-1>=0)
            {
                s.erase(i-1, 2);
                n-=2;
                i-=2;
            }
            else
            {
                s.erase(i, 1);
                n--;
                i--;
            }
        }
    }
    cout << s << "\n";
    return 0;
}