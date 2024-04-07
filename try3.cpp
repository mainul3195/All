#include <bits/stdc++.h>
using namespace std;
vector<long long> V(3);
long long solve1()
{
    int N = 3, overflow = 0;
    long long product = 1, A, x;
    x = pow(10, 18);

    for (int i = 0; i < N; i++)
    {
        A = V[i];
        if (A != 0 && x / A < product)
        {
            overflow = 1;
            break;
        }

        product *= A;
    }
    if (overflow)
        return -1;
    return product;
}
long long solve2()
{
    long long mul = 1;
    long long N = 1000000000000000000;

    for (long long i = 0; i < 3; i++)
    {
        if (V[i] > (N / mul))
        {
            return -1;
        }

        mul *= V[i];
    }
    return mul;
}
int32_t main()
{
    srand(time(0));
    do
    {
        V[0] = (long long)rand();
        V[1] = (long long)rand();
        V[2] = (long long)rand();
        cout << solve1() << " " << solve2() << "\n";
    } while (solve1() == solve2());
    cout << V[0] << " " << V[1] << "\n";

    return 0;
}
