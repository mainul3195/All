#include <bits/stdc++.h>
using namespace std;
void execute();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        execute();
    return 0;
}
void execute()
{
	long long n,r,k;
	cin >> n >> r;
    if(r<n)
	   k=(r*(r+1))/2;
    else
        k=((n-1)*n)/2+1;
	cout << k << "\n";
    return;
}