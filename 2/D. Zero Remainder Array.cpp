#include <bits/stdc++.h>
using namespace std;
void execute();
int i;
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
	int i,n,k,t,dif,x,y,ar[300000];
    long long max, b;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>t;
        ar[i]=((t-1)/k+1)*k-t;
    }
    sort(ar, ar+n);
    max=ar[0];
    for(i=0; i<n-1; i++)
    {
        if(max<ar[i+1])
            max=ar[i+1];
        if(ar[i]==ar[i+1] && ar[i])
        {
            t=b=ar[i];
            while(t==ar[i+1] && i<n-1)
            {
                b+=k;
                i++;
            }
            if(max<b)
                max=b;
        }
    }

    /*
    int max=ar[0];
    for(i=1; i<n; i++)
        if(ar[i]>max)
            max=ar[i];
            */
    if(max)
    max++;
    cout << max << "\n";
    return;

}