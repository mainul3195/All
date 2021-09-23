#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum=0;
	int temp=n;
	while(temp)
	{
		sum+=temp%10;
		temp/=10;
	}
	if(n%sum)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}