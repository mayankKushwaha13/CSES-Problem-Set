#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rrep(i,a,b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    fastio

    int n, x;
    cin >> n >> x;

    vi c(n);
    rep(i,0,n){
        cin >> c[i];
    }
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    rep(i, 1, x + 1){
        rep(j, 0, n){
            if(c[j] <= i){
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;
    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}