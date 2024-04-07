#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long m, n;
    cin >> m >> n;
    cout << (long long)sqrt(m) * (long long)sqrt(n) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // for (int h = 1; h <= 20; h++)
    //     for (int w = 1; w <= 20; w++)
    //     {
    //         vector<vector<int>> v(h + 1, vector<int>(w + 1, 0));
    //         for (int i = 1; i <= h; i++)
    //             for (int j = 1; j <= w; j++)
    //             {
    //                 for (int k = i; k <= h; k += i)
    //                     for (int l = j; l <= w; l += j)
    //                         v[k][l] = !v[k][l];
    //             }
    //         int count = 0;
    //         for (int i = 1; i <= h; i++)
    //             for (int j = 1; j <= w; j++)
    //                 if (v[i][j])
    //                     count++;
    //         cout << "h -> " << h << "\tw -> " << w << "\t ->" << count << "\n";
    //     }

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

#define lim 10000000

//#define ckbit(x) (fLd[(x)/32] & (1<<(x)%32))
//#define cngbit(x) (fLd[(x)/32] |= (1<<(x)%32))
//int fLd[lim/32+2];

#define ckbit(x) (fLd[(x)/64] & (1<<((x)%64)/2))
#define cngbit(x) (fLd[(x)/64] |= (1<<((x)%64)/2))
int fLd[lim/64+2];
vector<long long> prime;
void sieve()
{
    prime.push_back(2);
    for(long long i=3; i*i<=lim; i+=2)
        if(!ckbit(i))
            for(long long j = i*i; j<=lim; j+=2*i)
                cngbit(j);
    for(long long i=3; i<=lim; i+=2)
        if(!ckbit(i))
            prime.push_back(i);
    return;
}