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

bool dfs(int v, int par, vi&visited, vector<vi>&adj, int&cyclee, int&cycles) { // passing vertex and its parent vertex
    visited[v] = par;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cyclee = v;
            cycles = u;
            return true;
        }
        visited[u] = v;
        if (dfs(u, visited[u], visited, adj, cyclee, cycles))
            return true;
    }
    return false;
}


int main() {
    fastio

    // ifstream testcase("../tests/Graph Algorithms/round_trip_tests/6.in");
    // ifstream testout("../tests/Graph Algorithms/round_trip_tests/6.out");

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    rep(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n + 1, 0);
    bool cyclefound = false;
    int cycles = -1, cyclee = -1;
    rep(i, 1, n + 1){
        if(!vis[i]){
            if(dfs(i,i, vis, adj, cyclee,cycles)){
                cyclefound = true;
                break;
            }
        }
    }
    if(!cyclefound){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vi cycle;
        cycle.push_back(cycles);
        for(int v = cyclee; v != cycles; v = vis[v]){
            cycle.push_back(v);
        }
        cycle.push_back(cycles);
        cout << cycle.size() << endl;
        for(auto& v : cycle){
            cout << v << " ";
        }
        cout << endl;
    }
    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}