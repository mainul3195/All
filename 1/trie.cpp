#include<iostream>
#include<vector>
using namespace std;
struct node
{
    node *next[26], *root;
    int end_at_cur;
    node();
    void init();
};
node::node()
{
    end_at_cur = 0;
    for(int i=0; i<26; i++) next[i] = NULL;
}
void node::init()
{
    root = new node();
}
node makeTrie(vector<string>&list)
{
    node trie;
    trie.init();
    for(auto i: list)
    {
        node *cur = trie.root;
        for(auto j: i)
        {
            if(cur->next[j-'a'] == NULL)
                cur->next[j-'a'] = new node();
            cur = cur->next[j-'a'];
            cur->end_at_cur++;
        }
    }
    return trie;
}
int solve(string s, node trie)
{
    int i;
    node *cur = trie.root;
    for(i=0; i<s.size(); i++)
    {
        if(cur->next[s[i]-'a'] == NULL) return 0;
        cur = cur->next[s[i]-'a'];
    }
    return cur->end_at_cur;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string>list(n);
    for(auto &i: list)
        cin >> i;
    node trie = makeTrie(list);
    string s;
    while(m--)
    {
        cin >> s;
        cout << solve(s, trie) << "\n";
    }
    return 0;
}