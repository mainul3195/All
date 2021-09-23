#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define ll long long
void solve(){
 
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll prf[n+1]={0};
    rep(i,0,n){
        if(s[i]=='+')
            prf[i+1]=prf[i]+((i%2==0)?1:-1); 
        else
            prf[i+1]=prf[i]+((i%2==0)?-1:1);
    }
    for(int i=0; i<=n; i++)
        cout << prf[i] << " \n"[i==n];
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ans=prf[r]-prf[l-1];
        if(ans==0) cout<<0<<'\n';
        else if(ans%2) cout<<1<<'\n';
        else cout<<2<<'\n';
    }
    return;
}
int main(){
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      solve();
    }
    return 0;
}