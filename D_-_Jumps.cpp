#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<>> upper;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!i)
            lower.push(a);
        else
        {
            if (lower.size())
            {
                if (lower.top() >= a)
                    lower.push(a);
                else
                    upper.push(a);
            }
            else if (upper.size())
            {
                if (upper.top() <= a)
                    upper.push(a);
                else
                    lower.push(a);
            }
        }
        if (lower.size() == upper.size() + 2)
        {
            upper.push(lower.top());
            lower.pop();
        }
        else if (upper.size() == lower.size() + 2)
        {
            lower.push(upper.top());
            upper.pop();
        }
        if (upper.size() == lower.size())
            cout << fixed << setprecision(1) << (double)(upper.top() + lower.top()) / 2 << "\n";
        else
        {
            if (upper.size() > lower.size())
                cout << fixed << setprecision(1) << (double)upper.top() << "\n";
            else
                cout << fixed << setprecision(1) << (double)lower.top() << "\n";
        }
    }
    return 0;
}