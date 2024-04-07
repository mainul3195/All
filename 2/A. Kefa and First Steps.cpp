#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int count=1;
	int mx=0;
	int a;
	cin >> a;
	int b;
	for(int i=1; i<n; i++)
	{
		cin >> b;
		if(b<a)
		{
			mx=max(mx, count);
			count=1;
		}
		else
			count++;
		a=b;	
	}
	mx=max(mx, count);
	cout << mx << "\n";
	return 0;
}