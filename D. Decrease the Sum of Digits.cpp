#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string n;
		int s;
		cin >> n >> s;
		reverse(n.begin(), n.end());
		char temp[]="0";
		n.insert(n.size(), temp);
		int sum=0;
		for(int i=0; i<n.size(); i++)
			sum+=n[i]-48;
		char ans[25];
		for(int i=0; i<25; i++)
			ans[i]=0;
		ans[0]='0';
		int i=0;
	//	cout << sum << " " << s << "\n";
		while(sum>s)
		{
			int dig=(n[i]-48);
			int car=0;
			sum-=dig;
			n[i]='0';
			if(dig>0)
			{
				ans[i]=10-dig+48;
				car=1;
			}
			else
				ans[i]='0';
			for(int j=i+1; car; j++)
			{
				int t=(n[j]-48+car);
				if(t==10)
					sum-=n[j]-48;
				else
					sum++;
				n[j]=(t%10)+48;
				car=t/10;
			}
			i++;
		}
		int size=0;
		while(ans[++size]);
		reverse(ans, ans+size);
		cout << ans << "\n";
	}
}