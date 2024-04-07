#include<iostream>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        mp[j]++;
    }
    int count=0;
    for(auto i: mp)
        if(i.second%2)
            count++;
    cout << count << "\n";
    return 0;
}