#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];
	for(int i=1; i<n; i++)
		a[i]+=a[i-1];
	for(int i=n-2; i>=0; i--)
		b[i]+=b[i+1];
	int mx=0;
	for(int i=0; i<n; i++)
		if(a[i] + b[i] > mx)
			mx = a[i] + b[i];
	cout << mx << "\n";
	return 0;
}