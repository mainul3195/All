#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k, i, j, count=0,flag;
	string a;
	cin >> n >> k;
	while(n--)
	{
		cin >> a;
		int ar[10]={0};
		for(i=0; a[i]; i++)
			ar[a[i]-48]++;
		flag=1;
		for(i=0; i<=k; i++)
			if(!(ar[i]))
			{
				flag=0;
				break;
			}
		if(flag) count++;
	}
	cout << count;
	return 0;
}