#include<iostream>
#include<set>
#include<iterator>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    multiset<long long> q;
    if(cin >> n)
    {
        cout << n << "\n";
        q.insert(n);
    }
    auto it1=q.begin(), it2=q.begin();

    while(cin >> n)
    {
        q.insert(n);
        if(q.size()%2)
        {
            if(n>=*it2)
                it1++;
            else if(n<*it1)
                --it2;
            else ++it1, --it2;
        }
        else
        {
            if(n<*it1)
                it1--;
            // else if(n>=*it1 && n<*it2)
            //     it1++, it2--;
            else 
                it2++;
        }
        //cout << n <<"\t" <<  *it1 << "\t" << *it2 << "\t  ";
        cout << (*it1+ *it2)/2 << "\n";
    }
    return 0;
}