/*
( ) 1, 2
[ ] 3, 4
{ } 5, 6
< > 7, 8
(* *) 9, 10
*/

#include <bits/stdc++.h>
using namespace std;
bool opening(char c)
{
    return c == '(' || c == '{' || c == '[' || c == '<';
}
bool closing(char c)
{
    return c == ')' || c == '}' || c == ']' || c == '>';
}
map<char, char> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    mp[')'] = '(';
    mp['}'] = '{';
    mp[']'] = '[';
    mp['>'] = '<';
    while (getline(cin, s))
    {
        int cnt = 0;
        stack<char> st;
        bool done = 0;
        int double_found = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (opening(s[i]))
            {
                if (i + 1 < s.size() && s[i] == '(' && s[i + 1] == '*')
                    st.push('a'), i++, double_found++;
                else
                    st.push(s[i]);
                cnt++;
            }
            else if (closing(s[i]))
            {
                cnt++;
                if (st.empty() || st.top() != mp[s[i]])
                {
                    cout << "NO " << cnt << "\n";
                    done = 1;
                    break;
                }
                else
                    st.pop();
            }
            else if (s[i] == '*' && i + 1 < s.size() && s[i + 1] == ')')
            {
                i++;
                cnt++;
                double_found++;
                if (st.empty() || st.top() != 'a')
                {
                    cout << "NO " << cnt << "\n";
                    done = 1;
                    break;
                }
                else
                    st.pop();
            }
            else
                cnt++;
        }
        if (!done)
        {
            if (st.size())
                cout << "NO " << s.size() + 1 - double_found << "\n";
            else
                cout << "YES\n";
        }
    }
    return 0;
}