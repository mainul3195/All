#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, n;
	cin >> a >> b;
	int count=0;
	for(int i=a; i<=b; i++)
	{
		n=i;
		int num=0;
		while(n)
		{
			num=10*num+(n%10);
			n/=10;
		}
		if(i==num)
			count++;
	}
	cout << count << "\n";
	return 0;
}