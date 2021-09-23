#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string x,y;
	while(cin >> x >> y)
	{
		char ans[1000]={0};
		int l1=x.size(), l2=y.size();
		int j,k=0,len=0;
		for(int i=l2-1; i>=0; i--)
		{
			int mul=y[i]-48,car=0,p=l1-1;
			j=k++;
			do{
				int sum=0;
				if(ans[j])
					sum=ans[j]-48;
				int first=0;
				if(p>=0)
					first=x[p]-48;
				//cout << sum<< "\n";

				sum+=mul*first+car;
				car=sum/10;
				ans[j]=sum%10 + 48;
				//cout << ans << " " << sum << "\n";
				j++;
				p--;
			}while(car || p>=0);
			len=max(len,j);
		}
		int i;
		reverse(ans, ans+len);
		for( i=0; ans[i+1]; i++)
			if(ans[i]!=48)
				break;
		for(i; i<len; i++)
			cout << ans[i];		
		cout << "\n";
	}
	return 0;
}