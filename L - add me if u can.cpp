#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	char c[205];
	int n , i, car, j, k;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		i=car=0;
		int ac=1, bc=1;
		while(1)
		{
			if(ac)
			{
				if(!a[i])
				{
					j=0;
					ac=0;
				}
				else
					j=a[i]-48;
			}
			if(bc)
			{
				if(!b[i])
				{
					k=0;
					bc=0;
				}
				else
					k=b[i]-48;
			}

			c[i]=((j+k+car)%10)+48;
			//cout << c[i];
			car=(j+k+car)/10;
			i++;
			if(!car && !bc && !ac)
			{
				c[i]='\0';
				break;
			}
		}
		for(j=0; c[j]==48; j++);
		for(i--; c[i]==48; i--);
		for(; j<=i; j++)
			cout << c[j];
		cout << "\n";
	}
	return 0;
}