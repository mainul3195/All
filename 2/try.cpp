#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, x;
        scanf("%d %d", &n, &x);
        int ara[2 * n];
        for (int i = 0; i < 2 * n; i++)
        {
            scanf("%d", &ara[i]);
        }
        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; i < 2 * n - j - i; j++)
            {
                if (ara[j] > ara[j + 1])
                {
                    int temp = ara[j];
                    ara[j] = ara[j + 1];
                    ara[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < 2 * n; i++)
            cout << ara[i] << " \n"[i == 2 * n - 1];
    }
    return 0;
}