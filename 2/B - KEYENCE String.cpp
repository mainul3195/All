#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    bool ok=0;
    for(int i=0; i<=7; i++)
    {
        string t=s.substr(0,i);
        string t1=s.substr(s.size()-7+i, 7-i);
        string tmp= t+t1;
        if(tmp == "keyence")
        {
            ok=1;
            break;
        }
    }
    if(ok)
        cout <<"YES\n";
    else 
        cout << "NO\n";
    return 0;
}