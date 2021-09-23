#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int t;
	cin >> t;
	for(int tc=1; tc<=t; tc++)
	{
		int j,k,pc=0,uc=0,ic=0,c=0;
		double p,u,i,x;
		char a,b,mult;
		cin >> a;
		while(cin >> b)
		{
			if(c==2 || b=='\n')
				break;
			if(b=='=')
			{
				cin >> x >> mult;
				if(mult == 'm')
					x/=1000;
				else if(mult == 'k')
					x*=1000;
				else if(mult == 'M')
					x*=1000000;
				c++;
				//cout << x << " ";
				if(a=='P')
				{
					p=x;
					pc=1;
				}
				else if(a=='U')
				{
					u=x;
					uc=1;
				}
				else if(a=='I')
				{
					i=x;
					ic=1;
				}
			}
			a=b;
		}
		//cout << pc << " " << ic << " " << uc << "\n";
		cout << "Problem #" << tc << "\n";
		if(pc&&ic)
		{
			u=p/i;
			cout << "U=" << fixed << setprecision(2) << u << "V\n\n";
		}
		else if(pc&&uc)
		{
			i=p/u;
			cout << "I=" << fixed << setprecision(2) << i << "A\n\n";
		}
		else if(uc&&ic)
		{
			p=u*i;
			cout << "P=" << fixed << setprecision(2) << p << "W\n\n";
		}
	}
	return 0;
}