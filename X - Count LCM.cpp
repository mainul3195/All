#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long b;
	cin >> b;
	long long i,count=0;
	for(i=1; i*i<=b; i++)
	{
		if(!(b%i))
			count+=2;
		if(i*i==b)
			count--;
	}
	cout << count;
	return 0;
}