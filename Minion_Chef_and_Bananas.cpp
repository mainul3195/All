//////////////////////////////////////////////BISMILLAHIR RAHMANIR RAHEEM/////////////////////////////////////////////////////
/////////////////////////////////////////////////ASM SHUVO _ CSE,SUST/////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ld long double
#define pb push_back
#define endl '\n'
#define w(t)         \
    long long int t; \
    cin >> t;        \
    while (t--)
#define checkmate return 0
#define ll long long
#define ull unsigned long long
#define ld long double
#define pi 3.14159265358979323846264338327950;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define B begin()
#define E end()
#define endl '\n'
#define fast_i_o ios_base::sync_with_stdio(false), cin.tie(NULL)

lli n, h;
vector<lli> v;

bool KK(lli mid)
{
    lli cnt = 0;
    for (lli i = 0; i < n; i++)
    {
        cnt += (v[i] + mid - 1) / mid;
    }
    return cnt <= h;
}

int main()
{
    w(t)
    {
        cin >> n >> h;
        for (lli i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.pb(x);
        }
        sort(v.B, v.E);
        lli lo = 0, hi = 1e18, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (KK(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << (KK(lo) ? lo : hi) << endl;
        v.clear();
    }
    return 0;
}
