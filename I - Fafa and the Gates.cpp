#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	char c;
	int n,i,count=0,k=0,f;
	cin >> n >> c;
	if(c=='U') f=1, k=-1;
	else f=-1, k=1;
	for(i=1; i<n; i++)
	{
		cin >> c;
		if(c=='U') k--;
		else k++;
		if(k==f)
		{
			f*=-1;
			count++;
		}
	}
	cout << count;
	return 0;
}