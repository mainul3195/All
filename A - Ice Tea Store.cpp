#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long q,h,s,d,n;
	cin >> q >> h  >> s >> d >> n;
	if(q*2<h)
		h=2*q;
	if(2*h<s)
		s=2*h;
	if(2*s<d)
		d=2*s;
	cout << (n/2)*d + (n%2)*s << "\n";
	return 0;
}