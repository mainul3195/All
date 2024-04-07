#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> t(n+1, 0);
	int count=0;
	for(int i=0; i<n; i++)
	{
		int j;
		cin >> j;
		if(t[j]==i+1)
			count++;
		t[i+1]=j;
	}
	cout << count << "\n";
	return 0;
}