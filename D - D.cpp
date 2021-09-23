#include<bits/stdc++.h>
using namespace std;
struct segment
{
	int w, l, r;
	bool operator < (const segment &p) const
	{
		if(w==p.w)
			return l<p.l;
		return w>p.w;
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	set<segment> s1;
	set<int> s2;
	s2.insert(-1);
	s2.insert(n);
	int l=0;
	for(int i=0; i<n; i++)
	{
		s2.insert(i);
		cin >> a[i];
		if(a[i] != a[l])
		{
			int len=i-l;
			segment sg={len, l, i-1};
			s1.insert(sg);
			l=i;
		}
	}
	int len=n-l;
	segment sg={len, l, n-1};
	s1.insert(sg);
	int ans=0;
	while(s2.size()>2)
	{
		ans++;
		segment sg= *s1.begin();
		s1.erase(s1.begin());
		//cout << sg.l << " " << sg.r << "\n";
		int right_of_left= *--s2.find(sg.l);
		int left_of_right=*++ s2.find(sg.r);
		if(right_of_left!=-1 && left_of_right != n && a[left_of_right]== a[right_of_left])
		{
			int left_of_left = right_of_left, right_of_right=left_of_right, len=0;
			for(auto it= --s2.find(sg.l); it != s2.end(); --it)
			{
				if(a[left_of_left] != a[*it])
					break;
				len++;
				left_of_left = *it;
			}
			for(auto it = ++s2.find(sg.r); it != s2.end(); ++it)
			{
				if(a[right_of_right] != a[*it])
					break;
				len++;
				right_of_right= *it;
			}
			s1.insert({len, left_of_left, right_of_right});
		}
		s2.erase(s2.lower_bound(sg.l), s2.upper_bound(sg.r));
	}
	cout << ans << "\n";
	return 0;
}