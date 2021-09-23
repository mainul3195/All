#include<iostream>
#include<deque>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while(t--)    
    {
        deque<int> q;
        int n, m;
        cin >> n >> m;
        cout << "Case " << ++tc << ":\n";
        while(m--)
        {
            string s;
            int num;
            cin >> s;
            if(q.size()==n && (s=="pushLeft" || s=="pushRight"))
            {
                cin >> num;
                cout << "The queue is full\n";
                continue;
            }
            else if(q.size()==0 && (s=="popLeft" || s== "popRight"))
            {
                cout << "The queue is empty\n";
                continue;
            }
            if(s== "pushLeft")
            {
                cin >> num;
                q.push_front(num);
                cout << "Pushed in left: " << num << "\n";
            }
            else if(s== "pushRight")
            {
                cin >> num;
                q.push_back(num);
                cout << "Pushed in right: " << num << "\n";
            }
            else if(s=="popLeft")
            {
                int temp=q.front();
                q.pop_front();
                cout << "Popped from left: " << temp << "\n";
            }
            else if(s=="popRight")
            {
                int temp=q.back();
                q.pop_back();
                cout << "Popped from right: " << temp << "\n";
            }
        }
    }
    return 0;
}