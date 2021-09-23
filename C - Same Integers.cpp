#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ar[3];
	for(int i=0; i<3; i++)
		cin >> ar[i];
	int m=max(ar[0], max(ar[1], ar[2]));
	int tot=0;
	for(int i=0; i<3; i++)
		tot+=m-ar[i];
	if(!(tot%2))
		cout << tot/2;
	else
		cout << (tot+3)/2;
	return 0;
}