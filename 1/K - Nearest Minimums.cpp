#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	// for(auto i:v)
	// 	cout << i << "\n";
	int mn=2000000000;
	for(auto i:v)
		if(i<mn)
			mn=i;
	int in1,in2;
	bool flag=0;
	vector<int>fmn;
	for(int i=0; i<v.size(); i++)
		if(v[i]==mn)
			fmn.push_back(i);
	mn=2000000000;
	for(int i=1; i<fmn.size(); i++)
		if(fmn[i]-fmn[i-1]<mn)
			mn=fmn[i]-fmn[i-1];
	cout << mn;
	return 0;
}