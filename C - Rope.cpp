#include<bits/stdc++.h>
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	double r;
	cin >> n >> r;
	if(n==1)
	{
		cout << fixed << setprecision(2) << r*4*acos(0);
		return 0;
	}
	double l=0;
	vector< pair<double, double> > pos;
	for(int i=0; i<n; i++)
	{
		double a,b;
		cin >> a >> b;
		pair<double, double> p;
		p=make_pair(a,b);
		pos.push_back(p);
	}
	l+=sqrt((pos[0].first-pos[n-1].first)*(pos[0].first-pos[n-1].first)+(pos[0].second-pos[n-1].second)*(pos[0].second-pos[n-1].second));
	//cout << l << "\n";
	for(int i=1; i<n; i++)
		l+=sqrt((pos[i].first-pos[i-1].first)*(pos[i].first-pos[i-1].first)+(pos[i].second-pos[i-1].second)*(pos[i].second-pos[i-1].second));
	l+=4*acos(0)*r;
	cout <<fixed << setprecision(2) <<  l;
	return 0;
}