#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a;
	int i,j,k,sum=0,temp,count,r;
	cin >> a;
	for(i=0; a[i]; i++)
		sum+=a[i]-48;
	if(i==1) count=0;
	else count =1;
	while(sum/10)
	{
		count++;
		temp=0;
		while(sum)
		{
			r=sum%10;
			sum/=10;
			temp+=r;
		}
		sum=temp;
	}
	cout << count;
	return 0;
}