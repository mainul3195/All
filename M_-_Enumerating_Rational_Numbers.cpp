#include <bits/stdc++.h>
using namespace std;
#define lim 200003
long long phi[200005];
void find_phi()
{
    for (int i = 0; i <= lim; i++)
        phi[i] = i;
    for (int i = 2; i <= lim; i++)
        if (phi[i] == i)
            for (int j = i; j <= lim; j += i)
                phi[j] -= phi[j] / i;
    phi[1]++;
    for (int i = 1; i <= lim; i++)
        phi[i] += phi[i - 1];
    return;
}
int find_ind(long long x)
{
    int l = 0, r = lim, mid, ans = 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (phi[mid] < x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans + 1;
    
}
void solve()
{
    long long n;
    while (cin >> n && n)
    {
        int index = find_ind(n);
        // int index = lower_bound(phi, phi+lim, n) - phi;
        if (index == 1)
        {
            if (n == 1)
                cout << "0/1\n";
            else if (n == 2)
                cout << "1/1\n";
            continue;
        }
        n -= phi[index - 1];
        for (int i = 1; i <= index; i++)
        {
            if (__gcd(i, index) == 1)
            {
                n--;
                if (!n)
                {
                    cout << i << "/" << index << "\n";
                    break;
                }
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    find_phi();
    solve();
    return 0;
}