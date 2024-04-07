#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int lim=2*n;
		set<int> s;
		vector<int> notinlist;
		vector<int> v(lim,0),num(n);
		for(int i=0; i<n; i++)
		{
			cin >> num[i];
			v[num[i]-1]=1;
		}
		for(int i=0; i<lim; i++)
			if(!v[i])
				notinlist.push_back(i+1);
				//s.insert(i+1);
		// for(auto a: s)
		// 	cout << a << "\n";
		int xmin=0, xmax=0;
		// if(num[0]==1)
		// 	ans--;
		// for(int i=n-1; i>=0; i--)
		// {
		// 	if(*s.begin()>num[i])
		// 		break;
		// 	auto it=s.begin();
		// 	++it;
		// 	s.erase(s.begin(),it);
		// 	ans--;
		// }
		// cout << ans << "\n";
		for(int i=0,j=0; i<n; i++)
		{
			if(num[i]<notinlist[j])
			{
				xmin++;
				continue;
			}
			else
				j++;
		}
		for(int i=n-1, j=n-1; i>=0; i--)
		{
			if(num[i]>notinlist[j])
			{
				xmax++;
				continue;
			}
			else
				j--;
		}
		xmax=n-xmax;
		cout << xmax-xmin+1 << "\n";
	}
	return 0;
}