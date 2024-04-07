#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
void solve()
{
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    int mx = max(max(a, b), c);
    int required = n - (3 * mx - a - b - c);
    if (required >= 0 && required % 3 == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}