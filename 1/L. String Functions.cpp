#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	int n,q,a,b;
	scanf("%d %d", &n, &q);
	char c,t[20];
	list <char> str;
	list <char>::iterator it, it1, it2, it3, it4;
	for(a=0; a<n; a++)
	{
		cin >> c;
		str.push_back(c);
	}
	/*
	for(it=str.begin(); it!=str.end(); it++)
		cout << *it;
	cout<<"\n";
	*/
	while(q--)
	{
		scanf(" %s", t);
		if(strcmp(t, "pop_back")==0)
			str.pop_back();
		else if(strcmp(t, "front")==0)
				cout << str.front() << "\n";
		else if(strcmp(t,"back")==0)
				cout << str.back()<<"\n";
		else if(strcmp(t,"sort")==0)
		{
			scanf(" %d %d ", &a, &b);
			//cout << a << " " << b << "\n";
			it=str.begin();
			a--,b--;
			while(a--) it++;
			it1=it;
			it=str.begin();
			while(b--) it++;
			it2=it;
			c='a';
			str.push_back(c);
			it++;
			it3=it;
			int i, j;
			for(it4=it1; it1!=it2; it4++)
				for(it=++it1; it!=it3; it++)
					if(*it4>*it)
						*it4^=*it^=*it4^=*it;
			str.pop_back();
		}
		else if(strcmp(t,"reverse")==0)
		{
			scanf(" %d %d ", &a, &b);
			//cout << a << " " << b << "\n";
			it=str.begin();
			a--;
			while(a--) it++;
			it1=it;
			it=str.begin();
			while(b--) it++;
			it2=it;
			reverse(it1, it2);
		}
		else if(strcmp(t, "print")==0)
		{
			scanf("%d ", &a);
			a--;
			it=str.begin();
			while(a--) it++;
			cout << *it << "\n";
		}
		else if(strcmp(t,"push_back")==0)
		{
			scanf(" %c", &c);
			str.push_back(c);
		}
		else if(strcmp(t,"substr")==0)
		{
			scanf(" %d %d ", &a, &b);
			a--;
			while(a--) it++;
			it1=it;
			it=str.begin();
			while(b--) it++;
			it2=it;
			for(; it1!=it2; it1++)
				cout << *it1;
			cout << "\n";
		}
	}
	return 0;
}