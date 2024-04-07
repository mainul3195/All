#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int nod = 0, tmp = n;
        while(tmp)
        {
            nod++;
            tmp/=10;
        }
        int mnt = 1;
        for(int i = 1; i<nod; i++)
            mnt*=10;
        cout << n-mnt << "\n";
    }
    return 0;
}