#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1), b(n);
	for(int i=0; i<=n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];
	long long ans=0;
	for(int i=0; i<n; i++)
	{
		if(a[i]>b[i])
		{
			ans+=b[i];
		}
		else
		{
			ans+=a[i];
			b[i]-=a[i];
			if(a[i+1]>b[i])
			{
				a[i+1] -= b[i];
				ans+=b[i];
			}
			else
			{
				ans+=a[i+1];
				a[i+1] = 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}