#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, i, j;
		cin >> n >> k;
		vector <int> v;
		for(i=0; i<n; i++)
		{
			cin >> j;
			v.push_back(j);
		}
		int arr[n+5];
		int start=0, end=0;
		arr[0]=0;
		for(i=1; i<k; i++)
		{
			while(start<=end && v[i]>=v[arr[end]]) end--;
			end++;
			arr[end]=i;
		}

		cout << v[arr[start]] << " \n"[k==n];
		for(i=k; i<n; i++)
		{
			if(arr[start]==i-k)
				start++;
			while(start<=end && v[i]>=v[arr[end]]) end--;
			end++;
			arr[end]=i;
			cout << v[arr[start]] << " \n"[i==n-1];
		}
	}
	return 0;
}