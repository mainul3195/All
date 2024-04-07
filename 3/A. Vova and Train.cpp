#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int tm=n/k;
		for(int i=0; i<k; i++)
			for(int j=0; j<tm; j++)
				cout << (char)(97+i);

		for(int i=n%k; i>=1; i--)
			cout << "a";
		cout << "\n";
	}
	return 0;
}