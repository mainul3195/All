#include<bits/stdc++.h>
using namespace std;
int cnt;
void takeInput(int c,int *a)
{
	if(!c)
		return;
	int x,*y;
	cin >> x;
	y=(a+(cnt++));
	*y=x;
	//cout << x <<"\n";
	takeInput(c-1,(int*)a);

	return;
}
void calc(int *a, int *b, int n)
{
	if(!n)
		return;
	int *y;
	y=(b+n-1);
	*y=*(a+n-1)+*(b+n-1);
	calc(a,b,n-1);
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int c,r;
	cin >> r >> c;
	int i,j,k;
	int a[r][c],b[r][c];
	for(i=0; i<r; i++)
	{
		cnt=0;
		takeInput(c,(int*)a[i]);
	}
	for(i=0; i<r; i++)
	{
		cnt=0;
		takeInput(c,(int*)b[i]);
	}
	//cout << r << " " << c << "\n";

	calc( (int*)a, (int*)b, r*c);
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
			cout << b[i][j] << " \n"[j==c-1];
	return 0;
}