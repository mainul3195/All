#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> v, taken;
void printall(int prev = -1)
{
    if (taken.size() == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << taken[i] << " \n"[i == 5];
        return;
    }
    if (prev == k - 1)
        return;
    for (int i = prev + 1; i < k; i++)
    {
        taken.push_back(v[i]);
        printall(i);
        taken.pop_back();
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool frst = 1;
    while (cin >> k && k)
    {
        if (!frst)
            cout << "\n";
        frst = 0;
        v = vector<int>(k, 0);
        for (auto &i : v)
            cin >> i;
        taken.clear();
        printall();
    }
    return 0;
}