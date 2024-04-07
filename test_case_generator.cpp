#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    int n = 300000, q = 300000;
    cout << n << "\n";
    for(int i = 0; i<n; i++)
            cout << (rand()%2?1:-1)*(rand()%100000000) << " ";
        cout << "\n";
    cout << q << "\n";
    while(q--)
    {
        int t = rand()%2;
        if(t)
            cout << "assign " << rand()%n+1 << " " << (rand()%2?1:-1)*(rand()%100000000) << "\n";
        else
        {
            int l = rand()%n;
            int r = l + rand()%(n-l+1);
            cout << "torture " << l << " " << r << " " << (rand()%2?1:-1)*(rand()%100000000) << "\n";
        }
    }
    return 0;
}