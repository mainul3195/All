#include<bits/stdc++.h>
using namespace std;

//returns 0 base index of first found in text or -1
int matchString(const string &text,const string &pattern)
{
    if(text.size()<pattern.size()) return -1;
    vector<int>isp(pattern.size(), -1);
    int l = -1, r = 1;
    while(r<pattern.size())
    {
        if(pattern[l+1] == pattern[r]) isp[r++] = ++l;
        else
        {
            if(!l) l = -1;
            else if(l>0) l = isp[l-1];
            else r++;
        }
    }
    l = -1, r = 0;
    while(r<text.size() && l!=pattern.size()-1)
    {
        if(pattern[l+1] == text[r]) r++,l++;
        else l>=0? l = isp[l]: r++;
    }
    return l==pattern.size()-1? r - pattern.size(): -1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << matchString("aabaabaab", "abaab");
    return 0;
}