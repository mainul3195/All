#include<iostream>
#include<string>
using namespace std;
int h, w;
int x[]={1,1,1,0,-1,-1,-1,0}, y[]={1,0,-1,-1,-1,0,1,1};
bool isok(int a, int b)
{
	if(a<0 || a>=h || b<0 || b>=w)
		return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> h >> w;
	string s[h];
	for(int i=0; i<h; i++)
		cin >> s[i];
	for(int i=0; i<h ;i++)
		for(int j=0; j<w; j++)
		{
			int count=0;
			for(int k=0; k<8; k++)
			{
				int m=i+x[k];
				int n=j+y[k];
				if(isok(m,n) && s[m][n]=='#')
						count++;
			}
			if(s[i][j]=='.')
				s[i][j]=count+48;
		}
	for(int i=0; i<h ;i++)
		cout << s[i] << "\n";
	return 0;
}