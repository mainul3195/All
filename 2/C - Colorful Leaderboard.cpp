#include<iostream>
#include<algorithm>
using namespace std;
int col(int n)
{
	if(n>=1 && n<=399)
		return 0;
	if(n>=400 && n <= 799)
		return 1;
	if(n>=800 && n<=1199)
		return 2;
	if(n>=1200 && n<=1599)
		return 3;
	if(n>=1600 && n<=1999)
		return 4;
	if(n>=2000 && n<=2399)
		return 5;
	if(n>=2400 && n<=2799)
		return 6;
	if(n>=2800 && n<=3199)
		return 7;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int dif[10]={0};
	int boss=0, ans=0;;
	int j;
	for(int i=0; i<n;i++)
	{
		cin >> j ;
		if(j>=3200)
			boss++;
		else if(!dif[col(j)])
		{
			ans++;
			dif[col(j)]=1;
		}
	}
	cout << max(1,ans) << " " << ans+boss << "\n";
	return 0;
}