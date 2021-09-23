#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    long long ans=0;
    int n = s.size();
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='U')
            ans += 2*i + n-i-1;
        else 
            ans += i + 2*(n-i-1);
    }
    cout << ans << "\n";
    return 0;   
}
