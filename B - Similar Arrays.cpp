#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ml=1;
	for(int i=0; i<n; i++)
		ml*=3;
	int no3=1;
	int j;
	for(int i=0; i<n; i++)
	{
		cin >> j;
		if(j%2)
			no3*=1;
		else
			no3*=2;
	}
	cout << ml-no3 << "\n";
	return 0;
}