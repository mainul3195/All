#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar + n);
    cout << ar[n / 2] - ar[n / 2 - 1] << "\n";
    return 0;
}