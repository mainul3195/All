#include <bits/stdc++.h>
using namespace std;
vector<int> v, order;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while (getline(cin, str))
    {
        stringstream s(str);
        int num;
        v.clear();
        while (s >> num)
            v.push_back(num);
        if (v.size() == 1)
        {
            order = vector<int>(v[0] + 1);
            getline(cin, str);
            stringstream s(str);
            int count = 1;
            while (s >> num)
                order[count++] = num;
        }
        else
        {
            vector<int> student_order(v.size() + 1);
            int count = 1;
            for (auto i : v)
                student_order[i] = order[count++];

            vector<int> dp(student_order.size(), 1);
            for (int i = 2; i < student_order.size(); i++)
                for (int j = 1; j < i; j++)
                    if (student_order[i] > student_order[j])
                        dp[i] = max(dp[i], dp[j] + 1);
            int mx = -1;
            for (auto i : dp)
                mx = max(mx, i);
            cout << mx << "\n";
        }
    }

    return 0;
}