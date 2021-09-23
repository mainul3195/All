#include<iostream>
#include<string>
#include<map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<char, int>mp;
    mp['a']=1;
    mp['b']=2;
    mp['c']=3;
    mp['d']=1;
    mp['e']=2;
    mp['f']=3;
    mp['g']=1;
    mp['h']=2;
    mp['i']=3;
    mp['j']=1;
    mp['k']=2;
    mp['l']=3;
    mp['m']=1;
    mp['n']=2;
    mp['o']=3;
    mp['p']=1;
    mp['q']=2;
    mp['r']=3;
    mp['s']=4;
    mp['t']=1;
    mp['u']=2;
    mp['v']=3;
    mp['w']=1;
    mp['x']=2;
    mp['y']=3;
    mp['z']=4;
    mp[' ']=1;
    string s;
    int t, tc=0;
    cin >> t;
    getline(cin, s);
    while(t--)
    {
        getline(cin, s);
        int ans=0;
        for(auto i: s)
            ans += mp[i];
        cout << "Case #" << ++tc << ": " << ans << "\n";
    }
    return 0;
}   