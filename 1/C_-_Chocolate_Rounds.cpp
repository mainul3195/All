#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int ar[100] = {0};
    for (int i = 2; i <= 31; i++)
    {
        if(ar[i]==0)
        {
            cout << i << " ";
            for (int j = i; j <= 31; j+=i)
                ar[j] = 1;
        }
    }
        return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}