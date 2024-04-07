#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	if((!(n%2)))
	{
		cout << "2\n";
		while(!(n%2))
			n/=2;
	}

	for(long long i=3; i*i<=n; i+=2)
		if((!(n%i)))
		{
			cout << i <<  "\n";
			while(!(n%i))
				n/=i;
		}
	if(n!=1)
		cout << n << "\n";
	return 0;
}