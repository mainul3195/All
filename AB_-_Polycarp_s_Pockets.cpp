#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[101] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ar[x]++;
    }
    int mx = 0;
    for(int i =0 ; i<=100; i++)
        mx = max(mx, ar[i]);
    cout << mx << "\n";
    return 0;
}