#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i,j=0; j<n; j++)
	{
		cin >> i;
		v.push_back(i);
	}
	int i,j;
	for(i=1;  i<n && v[i]>v[i-1]; i++);
	i--;
	for(j=n-2; j>=0 && v[j]>v[j+1]; j-- );
	j++;
	if(i==j)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}