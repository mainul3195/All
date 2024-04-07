#include<iostream>
#include<string>
#include<algorithm>
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
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int l1=a.size(), l2=b.size();
		char ans[1005];
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
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		reverse(ans, ans+i);

		cout << "Case " << ++tc <<":\n" << a << " + " << b << " = " << ans << "\n";
		if(t)
			cout << "\n";
	}


}