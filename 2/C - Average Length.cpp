#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<double> x(n), y(n);
	for(int i=0; i<n; i++)
		cin >> x[i] >> y[i];
	double tot=0;
	for(int j=0; j<n-1; j++)
		for(int i=j+1; i<n; i++)
			tot += sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
	cout << fixed << setprecision(10) <<  (2*tot)/n << "\n";
	return 0;
}