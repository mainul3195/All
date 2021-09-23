/*
#include <bits/stdc++.h>
using namespace std;
void execute();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        execute();
    return 0;
}
void execute()
{

    return;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int a,b;
  list<char> mylist;
  list<char>::iterator it,it1,it2;
  for (int i=1; i<10; ++i) mylist.push_back(i+64);
    it= mylist.begin();
    a=2; b=7;
            a--;
            while(a--) it++;
            it1=it;
            it=mylist.begin();
            while(b--) it++;
            it2=it;
            reverse(it1, it2);
  cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    cout << ' ' << *it;

  cout << '\n';
  /*
sort(it1, it2);
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    cout << ' ' << *it;

  cout << '\n';
  */

  return 0;
}