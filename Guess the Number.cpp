#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int i=1;
        while(i<=1000)
        {
            cout << i*i  << "\n";
            int j;
            cin >> j;
            cout.flush();
            if(j)
                break;
            i++;
        }
    }
    return 0;
}