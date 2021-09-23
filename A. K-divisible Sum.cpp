#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        cout << ((k-n%k)%k +n -1)/n +1 << "\n";
    }
    return 0;
}