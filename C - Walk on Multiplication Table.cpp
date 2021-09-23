#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n;
	cin >> n;
	long long a=sqrt(n);
	while(a * (n/a) != n) a--;
	cout << a + n/a -2 << "\n";
	return 0;
}