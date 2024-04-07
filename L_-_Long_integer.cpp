#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;
        if(c=='+')
        {
            cin >> c;
            s.push_back(c);
        }
        else
            s.pop_back();
    }
    long long ans = 0;
    for(auto c: s)
    {
        ans = ans*10 + c - '0';
        ans %= mod;
    }
    cout << mod << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}