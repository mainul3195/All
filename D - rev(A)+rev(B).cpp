#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,tc=0;
	cin >> t;
	while(t--)
	{
		string a,b;
		cin >> a >> b;
		//cout << a;
		int l1=a.size(), l2=b.size();
		char ans[max(l1, l2)+5];
		int sum,carg=0,i;
		for(i=0; i<max(l1, l2); i++)
		{
			char x,y;
			if(i>=a.size())
				x=48;
			else
				x=a[i];
			if(i>=b.size())
				y=48;
			else
				y=b[i];
			sum=(x-'0')+(y-'0')+carg;
			carg=sum/10;
			sum%=10;
			ans[i]=sum+48;
		}
		if(carg==0)
			ans[i]=0;
		else
		{
			ans[i]=carg+48;
			ans[++i]=0;
		}
		int j,k;
		for(j=0; j<i; j++)
		{
			if(ans[j]!='0')
				break;
		}
		for(k=i-1; k>=0; k--)
			if(ans[k]!='0')
				break;

		for(i=j; i<=k; i++)
			cout << ans[i];
		cout << "\n";
	}
	return 0;

}