#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c, s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	while(~scanf("%c", &c))
	{
		int i, flag=1;
		for(i=0; s[i]; i++)
			if(s[i]==c)
			{
				printf("%c", s[i-1]);
				flag=0;
			}
		if(flag)
			printf("%c", c);
	}
	return 0;
}