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
		vector<int> v;
		cin >> n;

		int i,j,max=0,move=1,left_tot=0, right_tot=0,c=0;
		for(i=0; i<n; i++)
		{
			cin >> j;
			v.push_back(j);
		}

		i=0,j=n-1;
		while(move!=3)
		{
			c++;
			int t_max=0;
			if(move==1)
			{
				while(i<=j)
				{
					right_tot+=v[i];
					t_max+=v[i];
					i++;
					if(t_max>max)
					{
						max = t_max;
						move = 2;
						break;
					}
				}
				if(i>j)
					move = 3;
			}
			else if(move==2)
			{
				while(i<=j)
				{
					left_tot+=v[j];
					t_max+=v[j];
					j--;
					if(t_max>max)
					{
						max = t_max;
						move = 1;
						break;
					}
				}
				if(i>j)
					move = 3;
			}
		}
		cout << c << " " << right_tot << " " << left_tot << "\n";
	}
	return 0;
}