#include<bits/stdc++.h>
using namespace std;
bool ckprime(int n)
{
	if(n<3)
		return 1;
	if(!(n%2))
		return 0;
	for(int i=3; i*i<=n; i+=2)
		if(!(n%i))
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if(n<4)
		cout << "1";
	else if(!(n%2))
		cout << "2";
	else
	{
		if(ckprime(n))
			cout << "1";
		else
		{
			if(ckprime(n-2))
				cout << "2";
			else
				cout << "3";
		}
	}
	return 0;
}