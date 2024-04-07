#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// operations valid for only positive inputs
struct long_int
{
    string a;
    long_int()
    {
        a = "";
    }
    long_int(string s)
    {
        a = s;
    }
    long_int(long long l)
    {
        a = to_string(l);
    }
    long_int(int i)
    {
        a = to_string(i);
    }
    void append(char c)
    {
        a += c;
    }
    void append(string s)
    {
        a += s;
    }
    bool operator==(const long_int &x) const
    {
        return a == x.a;
    }
    bool operator==(const string &x) const
    {
        return a == x;
    }
    bool operator<(const long_int &x) const
    {
        return a.size() < x.a.size() || (a.size() == x.a.size() && a < x.a);
    }
    bool operator>(const long_int &x) const
    {
        return a.size() > x.a.size() || (a.size() == x.a.size() && a > x.a);
    }
    long_int operator+(const long_int x)
    {
        string frst = a;
        string scnd = x.a;
        reverse(frst.begin(), frst.end());
        reverse(scnd.begin(), scnd.end());
        string c;
        int carry = 0;
        for (int i = 0; i < frst.size() || i < scnd.size() || carry; i++)
        {
            int nm1 = (i < frst.size() ? frst[i] - '0' : 0);
            int nm2 = (i < scnd.size() ? scnd[i] - '0' : 0);
            int sum = nm1 + nm2 + carry;
            c.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(c.begin(), c.end());
        return long_int(c);
    }
    long_int operator-(const long_int x)
    {
        string frst = a;
        string scnd = x.a;
        bool minus = 0;
        if (long_int(frst) < x)
        {
            minus = 1;
            swap(frst, scnd);
        }
        reverse(frst.begin(), frst.end());
        reverse(scnd.begin(), scnd.end());
        string c;
        int carry = 0;
        for (int i = 0; i < frst.size() || i < scnd.size() || carry; i++)
        {
            int nm1 = (i < frst.size() ? frst[i] - '0' : 0);
            int nm2 = (i < scnd.size() ? scnd[i] - '0' : 0) + carry;
            if (nm1 < nm2)
            {
                nm1 += 10;
                carry = 1;
            }
            else
                carry = 0;
            int sub = nm1 - nm2;
            c.push_back(sub + '0');
        }
        while (c.size() && c.back() == '0')
            c.pop_back();
        if (c.empty())
            c.push_back('0');
        if (minus)
            c.push_back('-');
        reverse(c.begin(), c.end());
        return long_int(c);
    }
    long_int operator*(const long_int x)
    {
        string frst = a;
        string scnd = x.a;
        if (frst == "0" || scnd == "0")
            return long_int(0);

        vector<int> result(frst.size() + scnd.size(), 0);
        int i_n1 = 0;
        int i_n2 = 0;
        for (int i = frst.size() - 1; i >= 0; i--)
        {
            int carry = 0;
            int n1 = frst[i] - '0';
            i_n2 = 0;
            for (int j = scnd.size() - 1; j >= 0; j--)
            {
                int n2 = scnd[j] - '0';
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }
            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0)
            i--;
        string s = "";
        while (i >= 0)
            s += to_string(result[i--]);
        return long_int(s);
    }
    long_int operator/(const long_int x) // integer division
    {
        string frst = a;
        string scnd = x.a;
        if (scnd == "0")
            return long_int("nan");
        if (long_int(a) < x)
            return long_int(0);
        string cur_string = frst.substr(0, scnd.size());
        int i = scnd.size();
        string ans;
        while (1)
        {
            int mul = 0;
            while (!(long_int(cur_string) < long_int(scnd) * long_int(mul + 1)))
                mul++;
            if (ans.size() || mul)
                ans += mul + '0';
            cur_string = (long_int(cur_string) - (long_int(scnd) * long_int(mul))).a;
            if (i < frst.size())
            {
                cur_string += frst[i++];
                while (cur_string.size() > 1 && cur_string[0] == '0')
                    cur_string = cur_string.substr(1, cur_string.size() - 1);
            }
            else
                break;
        }
        return long_int(ans);
    }
};

string operate(string a, string operand, string b)
{
    long_int x(a), y(b);
    string ans;
    if (operand == "+")
        ans = (x + y).a;
    else if (operand == "-")
        ans = (x - y).a;
    else if (operand == "*")
        ans = (x * y).a;
    else
        ans = (x / y).a;
    if (ans == "nan" || ans[0] == '-' || ans.size() > 90)
        return "-1";
    return ans;
}
void calc(string &s)
{
    // cout << s << "\n\n\n";
    // return;
    string cur_string;
    vector<string> Stack;
    bool done = 0;
    for (auto c : s)
    {
        if (c == '(')
            Stack.push_back("(");
        else if (isOperator(c))
        {
            Stack.push_back(cur_string);
            string s;
            s += c;
            Stack.push_back(s);
            cur_string.clear();
        }
        else if (c == ')')
        {
            string op = Stack.back();
            Stack.pop_back();
            string val = Stack.back();
            Stack.pop_back();
            Stack.pop_back();
            if (val.size() > 90 || cur_string.size() > 90)
            {
                cout << "Error\n";
                done = 1;
                break;
            }
            string result = operate(val, op, cur_string);
            if (result == "-1")
            {
                cout << "Error\n";
                done = 1;
                break;
            }
            cur_string = result;
        }
        else
            cur_string += c;
    }
    if (!done)
        cout << cur_string << "\n";
    return;
}
void solve()
{
    string s;
    while (getline(cin, s))
    {
        string tmp;
        stringstream ss(s);
        char c;
        while (ss >> c)
            tmp += c;
        calc(tmp);
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("b.in", "r", stdin);
    solve();
    return 0;
}