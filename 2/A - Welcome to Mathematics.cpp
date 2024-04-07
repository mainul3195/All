#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int i=0;
	while(t--)
	{
		int arr[4];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr+3);
		cout << "Case " << ++i << ": ";
		if(arr[0]* arr[0] + arr[1]*arr[1]==arr[2]*arr[2])
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}