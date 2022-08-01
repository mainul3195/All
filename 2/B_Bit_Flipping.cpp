#include<bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<int> ans;
char inverse(char c)
{
    if(c=='1')
        return '0';
    return '1';
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        if((k-ans[i])%2)
            cout << inverse(s[i]);
        else
            cout << s[i];
    }
    cout << "\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
void solve()
{

    cin >> n >> k >> s;
    ans = vector<int>(n, 0);
    if(!k)
        print();
    else if(k==1)
    {
        int ind = n-1;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='1')
            {
                ind = i;
                break;
            }
        }
        ans[ind] = 1;
        print();
    }
    else if(k&1)
    {
        int tmp = k;
        for (int i = 0; tmp && i < n; i++)
        {
            if (s[i] == '1')
                ans[i]++, tmp--;
        }
        ans[n - 1] += tmp;
        print();
    }
    else
    {
        int tmp = k;
        for (int i = 0; tmp && i < n; i++)
        {
            if (s[i] == '0')
                ans[i]++, tmp--;
        }
        ans[n - 1] += tmp;
        print();
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}