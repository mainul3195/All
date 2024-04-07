#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, long long> &a, pair<char, long long> &b)
{
    return a.second > b.second;
}
void solve()
{
    int n;
    cin >> n;
    map<char, long long> contribution;
    set<char> last;
    int allocated[10] = {0};
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        last.insert(s[0]);
        int mul = 1;
        while (s.size())
        {
            char c = s.back();
            s.pop_back();
            contribution[c] += mul;
            mul *= 10;
        }
    }
    vector<pair<char, long long>> con;
    for (auto p : contribution)
        con.push_back(p);
    sort(con.begin(), con.end(), cmp);
    // for (auto [a, b] : con)
    //     cout << a << " " << b << "\n";
    map<char, int> mapped;
    for (auto [ch, _] : con)
    {
        // cout << "here -> " << ch << " " << _ << "\n";
        int start = (last.find(ch) != last.end());
        for (; start < 10; start++)
            if (!allocated[start])
            {
                mapped[ch] = start;
                allocated[start] = 1;
                break;
            }
        // for (int i = 0; i < 10; i++)
        //     cout << allocated[i] << " ";
        // cout << "\n";
    }
    // for (auto [a, b] : mapped)
    //     cout << a << " -> " << b << "\n";
    long long sum = 0;
    for (auto [ch, weight] : con)
        sum += (long long)weight * mapped[ch];
    cout << sum << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}