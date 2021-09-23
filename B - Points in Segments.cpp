#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        cout << "Case " << ++tc << ":\n";

        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        while(q--)
        {
            int l, r;
            cin >> l >> r;
            cout << upper_bound(v.begin(), v.end(), r)-lower_bound(v.begin(), v.end(), l) << "\n";
        }
    }
    return 0;
}