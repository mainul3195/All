#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, i, j, k;
	long long sum1=0, sum2=0,ans;
	cin >> n;
	vector < int > v;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	for(i=-1, j=n; ; )
	{
		if(sum1==sum2)
		{
			ans=sum1;
			i++;
			j--;
			if(i>=j)
				break;
			sum1+=v[i];
			sum2+=v[j];
		}
		else if(sum1>sum2)
		{
			j--;
			if(i>=j)
				break;
			sum2+=v[j];
		}
		else
		{
			i++;
			if(i>=j)
				break;
			sum1+=v[i];
		}
	}
	cout << ans;
	return 0;
}