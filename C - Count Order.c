#include<stdio.h>
#include<string.h>

void swap(char *a, char *b)
{
	char t;
	t = *a;
	*a = *b;
	*b = t;
	return;
}

char all[40322][9];
int count;
void permute(char a[], int start, int end)
{
	if(start == end)
	{
		strcpy(all[count++], a);
		return;
	}
	int i,j;
	char t;
	for(i=start; i<=end; i++)
	{
		t = a[i];
		for(j=i;j-1>=start;j--)
			swap(a+(j-1), a+j);
		a[j]=t;
		permute(a, start+1, end);
		t = a[start];
		for(j=start;j+1<=i; j++)
			swap(a+(j+1), a+j);
		a[j]=t;
	}
	return;
}
int main()
{
	char str1[9], str2[9];
	int i,n,b,t1;
	while(~scanf("%d", &n))
	{
		char a[]="123456789";
		a[n]=0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &b);
			str1[i]=b+48;
		}
		str1[i]=0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &b);
			str2[i]=b+48;
		}
		str2[i]=0;
		count = 0;
		permute(a, 0, n-1);
		for(i=0; i<count; i++)
		{
			if((strcmp(all[i], str2)==0)||(strcmp(all[i], str1)==0))
			{
				t1=i;
				if(strcmp(all[i], str2)==0)
				{
					for(; i<count; i++)
					{
						if(strcmp(all[i], str1)==0)
						{
							printf("%d\n", i-t1);
							i=count;
						}
					}
				}
				else
				{
					for(; i<count; i++)
					{
						if(strcmp(all[i], str2)==0)
						{
							printf("%d\n", i-t1);
							i=count;
						}
					}
				}
			}
		}
	}	
	return 0;
}