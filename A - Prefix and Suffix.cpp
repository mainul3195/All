#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    int mins;
    for(int i=n; i>=0; i--)
    {
        string a= s.substr(n-i, i);
        string b= t.substr(0, i);
        if(a==b)
        {
            mins=i;
            break;
        }
    }
    cout << 2*n-mins << "\n";
    return 0;
}