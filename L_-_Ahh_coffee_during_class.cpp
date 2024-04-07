#include <iostream>
using namespace std;
int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    int temp[200005] = {0};
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        temp[l]++;
        temp[r + 1]--;
    }
    for (int i = 1; i <= 200000; i++)
        temp[i] += temp[i - 1];
    for (int i = 0; i <= 200000; i++)
    {
        // if(temp[i]>=k)
        //     temp[i] = 1;
        // else
        //     temp[i] = 0;
        temp[i] = temp[i] >= k ? 1 : 0;
    }

    for (int i = 1; i <= 200000; i++)
        temp[i] += temp[i - 1];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << temp[r] - temp[l - 1] << "\n";
    }
    return 0;
}