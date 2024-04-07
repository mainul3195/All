#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ar[101]={0};
	int mx=0;
	for(int i=0; i<n; i++)
	{
		int j;
		cin >> j;
		ar[j]++;
		if(ar[j]>mx)
			mx=ar[j];
	}
	cout << mx;
	return 0;
}