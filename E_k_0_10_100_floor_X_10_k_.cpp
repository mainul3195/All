#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    vector<char>ans;
    cin >> s;
    int sum = 0;
    for(auto i: s)
        sum += i-48;
    // cout << s << " " << sum << "\n";
    reverse(s.begin(), s.end());
    int i = 0;
    long long car = 0, tot;
    // cout << s << "\n";
    while(sum || car)
    {
        tot = sum+car;
        ans.push_back(tot%10);
        car = tot/10;
        if(i<s.size())
            sum -= (s[i++]-48);
    }
    // cout << "yes\n";
    reverse(ans.begin(), ans.end());
    for(auto i: ans)
        cout << (char)(i+48) ;
        cout << "\n";
    return 0;
}