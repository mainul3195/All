#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isOperand(char &c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='^' || c=='%')
        return 0;
    return 1;
}
int outstackprec(char &c)
{
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c== '/' || c=='%')
        return 3;
    if(c=='^')
        return 6;
    if(c=='(')
        return 7;
    return 0;
}
int instackprec(char &c)
{
    if(c=='+' || c=='-')
        return 2;
    if(c=='*' || c== '/' || c=='%')
        return 4;
    if(c=='^')
        return 5;
    return 0;
}

string intopost(string &a)
{
    stack<char>st;
    string ans;
    for(int i=0; i<a.size();)
    {
        if(isOperand(a[i]))
            ans += a[i++];
        else
        {
            if(!st.empty() && instackprec(st.top()) == outstackprec(a[i]))
                st.pop(), i++;
            else if(st.empty() || instackprec(st.top())<outstackprec(a[i]))
                st.push(a[i++]);
            else 
            {
                ans += st.top();
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
long long operation(long long a, long long b, char c)
{
    switch(c)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a%b;
        case '^': 
        {
            long long mul;
            int i;
            for( mul = 1, i=0; i<b; i++)
                mul*=a;
            return mul;
        }
    }
    return 0;
}
long long calculate(string s)
{
    stack<char> st;
    for(auto c: s)
    {
        if(isOperand(c))
            st.push(c);
        else
        {
            long long b = st.top()-'0';
            st.pop();
            long long a = st.top()-'0';
            st.pop();
            long long ans = operation(a, b, c);
            st.push(ans+'0');
        }
    }
    return st.top()-'0';
}
int main()
{
    string s;
    cin >> s;
    cout << intopost(s) << "\n";
    cout << calculate(intopost(s)) << "\n";
    return 0;
}