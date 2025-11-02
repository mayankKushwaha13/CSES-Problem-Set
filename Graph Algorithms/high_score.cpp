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
    // ifstream testcase("../tests/Graph Algorithms/high_score_tests/6.in");
    // ifstream testout("../tests/Graph Algorithms/high_score_tests/6.out");
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    rep(i, 0, m){
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
    }
     vector<ll> dist(n + 1, -1e10);
    dist[1] = 0;
    rep (i,0,n-1){
        rep (j,1,n + 1){
            if (dist[j] != -1e10){
                for (pii x : adj[j]){
                    int v = x.first;
                    int w = x.second;
                    if (dist[j] + w > dist[v])
                        dist[v] = dist[j] + w;
                }
            }
        }
    }
    rep(u, 1, n + 1){
        if (dist[u] != -1e10){
            for (pii x : adj[u]){
                int v = x.first;
                int w = x.second;
                if (dist[u] + w > dist[v]){
                    queue<int> q;
                    q.push(u);
                    vi visited(n + 1, 0);
                    while (!q.empty()){
                        int node = q.front();
                        q.pop();
                        if (node == n){
                            cout << -1 << endl;
                            return 0;
                        }
                        visited[node] = 1;
                        for (pii x : adj[node]){
                            if (!visited[x.first]){
                                q.push(x.first);
                            }
                        }
                    }
                }
            }
        }
    }
 
    cout << dist[n] << endl;
    // long long output;
    // testout >> output;

    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}