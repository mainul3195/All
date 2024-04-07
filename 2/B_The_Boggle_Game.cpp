#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> frst(4, vector<char>(4)), scnd(4, vector<char>(4));
vector<string> possiblea, possibleb;
int x[] = {1, 1, 1, 0, -1, -1, -1, 0}, y[] = {1, 0, -1, -1, -1, 0, 1, 1};
bool valid_cor(int a, int b, vector<vector<int>> &vis)
{
    return a >= 0 && b >= 0 && a < 4 && b < 4 && (!vis[a][b]);
}
bool isVowel(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}
bool valid(string &s)
{
    int count = 0;
    for (auto c : s)
        if (isVowel(c))
            count++;
    return count == 2;
}

void find(int i, int j, vector<vector<char>> &v, vector<string> &store, vector<vector<int>> &vis, string &str)
{
    str.push_back(v[i][j]);
    vis[i][j] = 1;
    if (str.size() == 4)
    {
        if (valid(str))
            store.push_back(str);
        str.pop_back();
        vis[i][j] = 0;
        return;
    }
    for (int k = 0; k < 8; k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        if (valid_cor(ni, nj, vis))
            find(ni, nj, v, store, vis, str);
    }
    str.pop_back();
    vis[i][j] = 0;
    return;
}
void solve()
{
    char c;
    bool first = 1;
    while (cin >> c && c != '#')
    {
        if (!first)
            cout << "\n";
        if (first)
            first = 0;
        frst[0][0] = c;
        for (int i = 0; i < 4; i++)
            for (int j = i == 0; j < 8; j++)
            {
                if (j < 4)
                    cin >> frst[i][j];
                else
                    cin >> scnd[i][j - 4];
            }
        possiblea.clear();
        possibleb.clear();
        string s;
        vector<vector<int>> vis(4, vector<int>(4, 0));
        string str;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                find(i, j, frst, possiblea, vis, str);
                find(i, j, scnd, possibleb, vis, str);
            }

        map<string, int> mp;
        for (auto s : possiblea)
            mp[s] = 1;
        set<string> ans;
        for (auto s : possibleb)
            if (mp.count(s))
                ans.insert(s);
        if (ans.empty())
            cout << "There are no common words for this pair of boggle boards.\n";
        else
        {
            for (auto s : ans)
                cout << s << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}