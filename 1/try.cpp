#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define endl '\n'

void solve(int T) {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    ll sum = 0;
    for(int &i : v) cin >> i, sum += i;

    if(sum == x) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    sort(v.begin(), v.end());

    ll now = 0;
    for(int i=0; i<n-1; i++) {
        now += v[i];
        if(now == x) {
            swap(v[i], v[i+1]);
            break;
        }
    }

    for(int i : v) cout << i << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int T = 1;
    cin >> T;

    for(int t=1; t<=T; t++) solve(t);    
    
    return 0;
}
