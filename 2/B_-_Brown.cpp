#include <bits/stdc++.h>
using namespace std;
int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    case '/':
    case '*':
        return 3;
    }
    return 0;
}
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void solve()
{
    string s;
    stack<char> st;
    while (getline(cin, s) && s.size() == 1)
    {
        char c = s[0];
        if (isOperator(c))
        {
            while (st.size() && precedence(st.top()) >= precedence(c))
            {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        }
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else
            cout << c;
    }
    while (st.size())
    {
        cout << st.top();
        st.pop();
    }
    cout << "\n";
    return;
}
int main()
{
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (t--)
    {
        solve();
        if(t)
            cout << "\n";
    }
    return 0;
}