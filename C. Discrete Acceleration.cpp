#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, l;
		cin >> n >> l;
		int velocity=1;
		vector<int> flag(n+2);
		flag[0]=0;
		vector<double>front(n+2), back(n+2);
		front[0]=back[n+1]=0;
		for(int i=1;i<=n; i++)
		{
			cin >> flag[i];
			front[i]=front[i-1]+((double)flag[i]-flag[i-1])/(double)velocity;
			velocity++;
		}
		flag[n+1]=l;
		front[n+1]=front[n]+((double)flag[n+1]-flag[n])/(double)velocity;
		velocity=1;
		for(int i=n; i>0; i--)
			back[i]=back[i+1]+((double)flag[i+1]-flag[i])/(double)velocity++;
		back[0]=back[1]+((double)flag[1]-flag[0])/(double)velocity;
		// for(int i=0; i<n+2; i++)
		// 	cout << front[i] << "\t\t" << back[i] << "\n";
		for(int i=0; i<n+2; i++)
		{
			if(front[i]==back[i])
			{
				cout << fixed << setprecision(9) << front[i];
				break;
			}
			else if(front[i]>back[i])
			{
				double dis=0;
				if(front[i-1]<back[i])
					dis=(back[i]-front[i-1])*i;
				else if(front[i-1]>back[i])
					dis=(front[i-1]-back[i])*(n-i+2);
				cout << fixed << setprecision(9) << max(front[i-1], back[i])+(flag[i]-flag[i-1]-dis)/(n+2) << "\n";
				break;
			}
		}

	}
}