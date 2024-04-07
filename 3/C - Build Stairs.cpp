#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n+1);
	v[0]=0;
	for(int i=0; i<n; i++)
		cin >> v[i+1];
	bool ok=1;
	for(int i=0; i<n; i++)
	{
		if(v[i]>v[i+1])
		{
			ok=0;
			break;
		}
		if(v[i]<v[i+1])
			v[i+1]--;
	}
	if(ok)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}