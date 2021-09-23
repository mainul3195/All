#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long x, y;
	cin >> x >> y;
	int c=0;
	for(long long i=y/x; i; i/=2) c++;
	cout << c << "\n";
	return 0;
}