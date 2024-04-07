#include <bits/stdc++.h>
using namespace std;

vector<int> l, r;
int tot;
bool possible(int n)
{
    int mx = 0;
    for (int i = 0; i <= n; i++)
        mx = max(l[i] + r[n - i], mx);
    if (tot - mx <= n)
        return 1;
    return 0;
}
void solve()
{
    string s;
    cin >> s;
    int left, right;
    for (left = 0; left < s.size() && s[left] == '0'; left++)
        ;
    for (right = s.size() - 1; left >= 0 && s[right] == '0'; right--)
        ;
    if (right <= left)
    {
        cout << "0\n";
        return;
    }
    l.clear();
    r.clear();
    int prev = 0;
    for (int i = left; i <= right; i++)
    {
        if (s[i] == '1')
        {
            l.push_back(prev);
            prev = 0;
        }
        else
            prev++;
    }
    for (int i = right; i >= left; i--)
    {
        if (s[i] == '1')
        {
            r.push_back(prev);
            prev = 0;
        }
        else
            prev++;
    }
    l.push_back(0);
    r.push_back(0);
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    tot = 0;
    for (auto i : l)
        tot += i;
    for (int i = 1; i < l.size(); i++)
    {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    int lb = 0, rb = l.size() - 2, ans;
    while (lb <= rb)
    {
        int mid = (lb + rb) / 2;
        if (possible(mid))
        {
            ans = mid;
            rb = mid - 1;
        }
        else
            lb = mid + 1;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}