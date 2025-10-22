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

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
    rep(i, 0, m){
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    rep(i, 1, n + 1) dist[i][i] = 0;
    rep(k, 1, n + 1){
        rep(i, 1, n + 1){
            rep(j, 1, n + 1){
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    rep(i, 0, q){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == LLONG_MAX) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }

    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}