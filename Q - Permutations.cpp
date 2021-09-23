#include<bits/stdc++.h>
using namespace std;


bool check_permutation(int start, int end, int n, vector<int> &v)//check permutation from index start to end ( 1 based )
{
	vector<bool> flg(n+1,0);
	int i;
	for(i=start; i<=end; i++)//checking the first part if it is a perfect permutation
		flg[v[i-1]]=1;
	for(i=1; i<=end-start+1; i++)
		if(!flg[i])
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,i,j,k,max=0,c=0;
		cin >> n;
		vector<int> v;
		for(i=0; i<n; i++)//input and finding max value
		{
			cin >> j;
			v.push_back(j);
			if(j>max)
				max=j;
		}
		if(max>=n)
		{
			cout << "0\n";
			continue;
		}
		bool first=0 , second=0;

		if(check_permutation(1, n-max, n,v) && check_permutation(n-max+1, n, n,v))//keep track of the first answer
		{
			c++;//c==count(nummber of ways)
			first=1;
		}
		if(max*2 != n && check_permutation(1, max, n, v) && check_permutation(max+1, n, n,v))
		{
			c++;
			second=1;
		}
		//output part
		cout << c << "\n";
		if(first)
			cout << n-max << " " << max << "\n";
		if(second)
			cout << max << " " << n-max << "\n";
	}
	return 0;
}