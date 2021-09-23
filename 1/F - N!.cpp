#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<string>v(1005);
	char ans[10000]={0}, num1[10000]={0};
	int n,len=1,x;
	ans[0]='1';
	v[0].insert(0,ans);
	for(int i=1; i<1001; i++)
	{

		int no_of_digit, temp=i;
		for(no_of_digit=0; temp; no_of_digit++, temp/=10);
		int first_digit=0;
		for(int j=0; ans[j]; j++)
		{
			int p=first_digit++,car=0;
			int sum=i*(ans[j]-48);
			temp=sum;
			int digit;
			for(digit=0; temp; digit++, temp/=10);
			int d=max(no_of_digit,digit);
			while(d-->=1 || car)
			{
				int temporary=0;
				if(num1[p])
					temporary=num1[p]-48;
				temporary+=car+sum%10;
				car=temporary/10;
				sum/=10;
				num1[p++]=temporary%10 + 48;
			}
			len=max(len,p);
		}
		char str[len+2]={0};
		for(int x=0; num1[x]; x++)
			str[len-x-1]=ans[x]=num1[x];
		for(int x=0; num1[x]; x++)
			num1[x]=0;
		//cout << str << "\n";
		v[i].insert(0,str);
	}
	while(cin >> n)
		cout << n << "!\n" << v[n] << "\n";
	return 0;
}