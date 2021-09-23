#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    string a="", b="";
    int count=0;
    for(int i=0; ; i++)
    {
        if(a==b)
        {
            if(i==s.size())break;
            b+= s.substr(i,1);
            continue;
        }
        count++;
        a=b;
        if(i==s.size())break;
        b=s.substr(i, 1);
    }
    cout << count << "\n";
    return 0;
}