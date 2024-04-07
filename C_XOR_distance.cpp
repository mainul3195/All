#include <bits/stdc++.h>
using namespace std;
vector<long long> pw;
void solve()
{
    long long a, b, k;
    cin >> a >> b >> k;
    string ab = "", bb = "";
    if (b > a)
        swap(a, b);
    while (a)
    {
        ab.push_back((a % 2) + '0');
        a >>= 1;
    }
    while (b)
    {
        bb.push_back((b % 2) + '0');
        b >>= 1;
    }
    while (bb.size() < ab.size())
        bb.push_back('0');
    long long taken = 0;
    for(int i = ab.size()-1; i>=0; i--)
    {
        if(ab[i]>bb[i])
        {
            for(int j = i-1; j>=0; j--)
            {
                if(ab[j]>bb[j] && taken+pw[j]<=k)
                {
                    taken += pw[j];
                    swap(ab[j], bb[j]);
                }
            }
            break;
        }
    }
    long long frst = 0, scnd = 0;
    for(int i = 0; i<ab.size(); i++)
    {
        if(ab[i] == '1')
            frst += pw[i];
        if(bb[i] == '1')
            scnd += pw[i];
    }
    cout << frst - scnd << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    long long ml = 1;
    for (int i = 0; i < 62; i++)
    {
        pw.push_back(ml);
        ml <<= 1;
    }
    cin >> t;
    while (t--)
        solve();
    return 0;
}