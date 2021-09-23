#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	double x2,x1,y1,y2,x,y;
	double ang, mag;
	//cout << sin(4.71239);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		mag=sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2);
		double a1,a2;
		if(!x1 && !y1)
			a1=0;
		else
			a1=atan(y1/x1);
		if(x1<=0 && y1<=0)
			a1 = 2*acos(0)+a1;
		else if(x1<=0 && y1>=0)
			a1 = 2*acos(0)-a1;	
		else if(x1>=0 && y1<=0)
			a1 = -1*a1;		
		if(!x2 && !y2)
			a2=0;
		else
			a2=atan(y2/x2);
		if(x2<=0 && y2<=0)
			a2 = 2*acos(0)+a2;
		else if(x2<=0 && y2>=0)
			a2 = 2*acos(0)-a2;	
		else if(x2>=0 && y2<=0)
			a2 = -1*a2;	
		//cout << a1 << " " << a2 << "\n" ;
		ang = a1 + a2;
		//cout << mag << " " << ang << "\n";
		x=mag*cos(ang);
		y=mag*sin(ang);
		if(fabs(x-0)<.0000000001)
			x=0;
		if(fabs(y-0)<.0000000001)
			y=0;
		cout << x << " " << y << "\n";
	}
	return 0;
}