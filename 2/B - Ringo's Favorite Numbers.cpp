#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int d, n;
	cin >> d >> n;
	if(n==100)
		n++;
	for(int i=0; i<d; i++)
		n*=100;

	cout << n << "\n";
	return 0;
}