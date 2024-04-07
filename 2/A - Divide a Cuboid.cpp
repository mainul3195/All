#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	cout << (long long)a[0]*a[1]*((a[2]+1)/2) - (long long)a[0]*a[1]*(a[2]/2) << "\n";
	return 0;
}