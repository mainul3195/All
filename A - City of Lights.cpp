#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n+1, 1);
    int k;
    cin >> k;
    vector<int> start(k);
    int one_count=0;
    bool ok=1;
    for(int i=0; i<k; i++)
    {
        cin >> start[i];

        if(ok && start[i]==1)
            one_count++;
        else ok=0;
    }
    if(one_count)
    {
        cout << n << "\n";
        return 0;
    }
    int off_count = 0;
    for(int i=0; i<k; i++)
    {
        int local = off_count, j, tmp=start[i];
        for(j=1; tmp<=n;)
        {
            if(v[tmp])
            {
                v[tmp] = 0;
                local++;
            }
            else
            {
                v[tmp] = 1;
                local --;
            }
            j++;
            tmp = start[i]*j;
        }
        off_count = max(off_count, local);
    }
    cout << off_count << "\n";
    return 0;
}