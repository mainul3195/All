// // #include<bits/stdc++.h>
// // using namespace std;
// // struct point
// // {
// // 	double x, y;
// // };
// // int main()
// // {
// // 	int n;
// // 	cin >> n;
// // 	vector<point> v(n);
// // 	for(auto &i: v)
// // 		cin >> i.x >> i.y;

// // 	double sum_of_xi=0;
// // 	for(auto i: v)
// // 		sum_of_xi += i.x;

// // 	double sum_of_yi = 0;
// // 	for(auto i: v)
// // 		sum_of_yi += i.y;

// // 	double sum_of_xiyi=0;
// // 	for(auto i: v)
// // 		sum_of_xiyi += i.x*i.y;

// // 	double sum_of_xisquare=0;
// // 	for(auto i: v)
// // 		sum_of_xisquare += i.x*i.x;

// // 	double a1 = (n*sum_of_xiyi - sum_of_xi*sum_of_yi)/(n*sum_of_xisquare - sum_of_xi*sum_of_xi);
// // 	double a0 = (sum_of_yi - a1*sum_of_xi)/n;
// // 	cout << fixed << setprecision(3) <<"a1 = "  << a1 << "\na0 = " << a0 << "\n";
// // 	return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define mod 998244353
// long long ans(long long base, long long power)
// {
// 	if(!power)
// 		return 1;
// 	if(power&1)
// 		return base*ans(base, power-1)%mod;
// 	long long t = ans(base, power/2);
// 	return t*t%mod;
// }
// int main()
// {
// 	cout << ans(26,5);
// 	return 0;
// }

// // 1
// // 10 3
// // 1 9
// // 2 10

// // 1  2  3  4  5  6  7  8  9  10
// // 26 26 26 26 26 1  1  1  1  1


// // ceil(n/2)

#include<bits/stdc++.h>

using namespace std;

#define fastio            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll                long long
#define ld                long double
#define fr                first
#define sc                second
#define pll               pair<ll,ll>
#define tll               tuple<ll,ll,ll>
#define vll               vector<ll>
#define bp(x)             __builtin_popcountll(x)
#define all(a)            a.begin(),a.end()
#define cb(a,i)           (a>>i&1)


#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
   cerr << *it << "=" << a << " ! ";
   err(++it, args...);
}

const ll N=5e6+7, M=998244353, inf=2e18;
map<ll,ll> m;
ll tt,n,q,l,r,i,z,C,tc;

ll bmd(ll n,ll k)
{
   ll R=1;
   while(k){
      R=(k&1)?R*n%M:R;
      k>>=1;
      n=n*n%M;
   }
   return R%M;
}

int main()
{
   fastio
   cin>>tt;
   while(tt--){
      cin>>n>>q;
      m={}; C=0;
      for(i=1; i<=n+1; i++) m[i]=26;
      auto upd=[&](ll l,ll r){
         ll i;
         for(i=l; i<=r; i++) m[i]=1;
      };
      while(q--){
         cin>>l>>r;
         if(l==r) continue;
         z=r-l+1;
         upd(r-z/2+1,r);
      }
      for(auto it=m.begin(); it->fr!=n+1; it=m.erase(it)){
         if(it->sc==26) C+=next(it)->fr-it->fr;
      }
	  cout << C << "\n";
      cout<<"Case "<<++tc<<": "<<bmd(26,C)<<"\n";
   }
}



/* stuff you should look for
   * obvious case
   * int overflow, array bounds
   * special cases (n=1?)
   * do smth instead of nothing and stay organized
   * WRITE STUFF DOWN
   * DON'T GET STUCK ON ONE APPROACH
*/




1  2  3  4  5  6  7  8  9  10  11  12
26 26 1  1  1  1  1  26 26 26  1   26
C = 6

1 3
1 5
4 6
10 11
6 10















