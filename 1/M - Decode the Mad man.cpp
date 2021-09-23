#include<iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<char, char>mp;
    char str[]="qwertyuiop[]\\asdfghjkl;'zxcvbnm,./`1234567890-=", str2[]="QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?~!@#$%^&*()_+";
    for(int i=2; i<47; i++)
        mp[str[i]]=str[i-2];
    for(int i=2; i<47; i++)
        mp[str2[i]]=str[i-2];
    string s;
    while(getline(cin, s)){
    int ans=0;
    for(auto i: s)
    {
        if(i==' ' || i=='\n')
            cout << ' ' ;
        else
            cout << mp[i];
    }
    }
    return 0;
}   