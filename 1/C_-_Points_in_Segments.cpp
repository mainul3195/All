#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ar[m + 2] = {0};
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        ar[l]++;
        ar[r + 1]--;
    }
    for (int i = 1; i <= m; i++)
        ar[i] = ar[i - 1] + ar[i];
    int count = 0;
    for (int i = 1; i <= m; i++)
        if (ar[i] == 0)
            count++;
    cout << count << "\n";
    for (int i = 1; i <= m; i++)
        if (ar[i] == 0)
            cout << i << " ";
    return 0;
}