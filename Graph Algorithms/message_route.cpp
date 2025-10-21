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

    // ifstream testcase("../tests/Graph Algorithms/message_route_tests/5.in");
    // ifstream testout("../tests/Graph Algorithms/message_route_tests/5.out");

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    rep(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(n + 1, 1e9);
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int dis = pq.top().fi;
        int node = pq.top().se;
        pq.pop();

        for(auto& adjNode : adj[node]){
            if(dist[adjNode] > dis + 1){
                dist[adjNode] = dis + 1;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    if(dist[n] == 1e9){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else{
        int k = dist[n] + 1;
        cout << k << endl;
        vi path;
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            path.push_back(node);
            for(auto& adjNode : adj[node]){
                if(dist[adjNode] == dist[node] - 1){
                    q.push(adjNode);
                    break;
                }
            }
        }
        reverse(path.begin(), path.end());
        for(auto& x : path) cout << x << " ";
        cout << endl;
    }
    return 0;
}