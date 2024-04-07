#include <bits/stdc++.h>
using namespace std;
#define int long long
int digit[3];
map<long long, int> taken;
long long num = 0;
vector<long long> allnums, allgood;
void all_possible(int i = 0)
{
    if (i == 9)
    {
        taken[num] = 1;
        return;
    }
    for (int j = 0; j < 3; j++)
    {
        if (!num)
            all_possible(i + 1);
        num = num * 10 + digit[j];
        all_possible(i + 1);
        num /= 10;
    }
}
bool ifok(int n)
{
    if (!n)
        return 0;
    int nod = 0, tot = 0;
    vector<int> dig;
    while (n)
    {
        nod++;
        tot += n % 10;
        dig.push_back(n % 10);
        n /= 10;
    }
    if (nod == 1)
        return 0;
    if (tot % nod == 0)
    {
        int d = tot / nod;
        for (auto i : dig)
            if (d == i)
                return true;
    }
    return false;
}
int indx(int n)
{
    int ans = 0, l = 0, r = allgood.size() - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (allgood[mid] <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
void solve()
{
    for (int i = 0; i < 3; i++)
        cin >> digit[i];
    all_possible();
    for (auto [n, k] : taken)
        allnums.push_back(n);
    for (auto i : allnums)
        if (ifok(i))
            allgood.push_back(i);
    allgood.push_back(0);
    sort(allgood.begin(), allgood.end());
    int q;
    cin >> q;
    int ans = -1, tot = -1;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        int tmp = indx(r) - indx(l - 1);
        if (tmp > tot)
        {
            tot = tmp;
            ans = i;
        }
    }
    cout << ans << "\n";
    // for (auto i : allgood)
    //     cout << i << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}