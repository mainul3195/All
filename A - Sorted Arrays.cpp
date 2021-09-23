#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    int count=0,last=-1;
    for(int i=1; i<n;)
    {
        while(i<n && v[i]==v[i-1]) i++;
        if(i<n && v[i]>v[i-1])
        {
            while(i<n && v[i]>=v[i-1])i++;
            count++;
            i++;
        }
        else if(i<n && v[i]<v[i-1])
        {
            while(i<n && v[i]<=v[i-1]) i++;
            i++;
            count++;
        }
        last=i;
    }
    if(last == n || n==1)
        count ++;
    cout << count << "\n";
    return 0;
}