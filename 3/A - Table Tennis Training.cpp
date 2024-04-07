#include<iostream>
#include<limits>
using namespace std;
long long lmn(long long a, long long b)
{
	return a<b? a:b;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, a, b;
	cin >> n >> a >> b;
	if(!((b-a)%2))
		cout << (b-a)/2 << "\n";
	else
		cout << lmn((a+b-1)/2, n-(a+b-1)/2) << "\n";
	return 0;
}