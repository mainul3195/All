#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,tc=0;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v;
		int i,j;
		for(i=0; i<n ;i++)
		{
			cin >> j;
			v.push_back(j);
		}
		long long maxsum=LLONG_MIN,sum=0;
		int start_index, end_index,in=1;
		for(i=0; i<n ;i++)
		{
			sum+=v[i];
			if(sum>maxsum)
			{
				maxsum=sum;
				end_index=i+1;
				start_index=in;
			}
			if(sum<0)
			{
				in=i+2;
				sum=0;
			}
		}
		cout << "Case " << ++tc << ":\n" << maxsum<< " " << start_index << " " << end_index << "\n";
		if(t)
			cout << "\n";
	}
	return 0;
}