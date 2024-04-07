#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    if(s<t)
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}