#include<iostream>
using namespace std;
int main()
{
    long long h, w;
    cin >> h >> w;
    long long mins =0;
    if(h>1)
        mins += 2*w;
    if(w>1)
        mins += 2*h;
    if(h>1 && w>1)
        mins -= 4;
    cout << h*w - mins << "\n";;

    return 0;
}