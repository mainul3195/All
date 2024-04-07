#include <bits/stdc++.h>
using namespace std;
int n, k;
struct trie
{
    struct node
    {
        node *next[26];
        int val;
        node()
        {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
            val = 0;
        }
    };
    node *root;
    trie()
    {
        root = new node();
    }
    void insert(string s)
    {
        node *cur = root;
        for (auto c : s)
        {
            if (cur->next[c - 'a'] == NULL)
                cur->next[c - 'a'] = new node();
            cur = cur->next[c - 'a'];
        }
    }
    void print()
    {
        node *cur = root;
        queue<node *> q;
        q.push(cur);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
                if (u->next[i] != NULL)
                {
                    cout << (char)(i + 'a');
                    q.push(u->next[i]);
                }
        }
        return;
    }
    bool can_win(node *cur)
    {
        for(int i = 0; i<26; i++)
        {
            if(cur->next[i] == NULL)
                continue;
            if(can_win(cur->next[i]) == 0)
                return 1;
        }
        return 0;
    }
    bool can_lose(node *cur)
    {
        for(int i = 0; i<26; i++)
        {
            if(cur->next[i] == NULL)
                continue;
            if(can_lose(cur->next[i])==0)
                return 1;
        }
        return 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    trie t;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        t.insert(s);
    }
    bool cw = t.can_win(t.root);

    if (t.root->val == 0)
        cout << "Second\n";
    else
    {
        if (k & 1)
            cout << "First\n";
        else
            cout << "Second\n";
    }
    return 0;
}