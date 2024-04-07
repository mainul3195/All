#include<bits/stdc++.h>
using namespace std;
#define mod 10000007
vector<int> dp;
int a, b, c, d, e, f;
int fn(int n) {
    if(~dp[n]) return dp[n];
    if (n == 0) return a%mod;
    if (n == 1) return b%mod;
    if (n == 2) return c%mod;
    if (n == 3) return d%mod;
    if (n == 4) return e%mod;
    if (n == 5) return f%mod;
    return dp[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%mod;
}
int main() {
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        dp = vector<int> (n+5, -1);
        printf("Case %d: %d\n", caseno, fn(n) % mod);
    }
    return 0;
}