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

    int n, m;
    cin >> n >> m;

    vector<vi> adj(n + 1);
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vi indegree(n + 1, 0);
    rep(i, 1, n + 1){
        for(auto& v : adj[i]){
            indegree[v]++;
        }
    }
    queue<int> q;
    rep(i, 1, n + 1){
        if(indegree[i] == 0) q.push(i);
    }
    vi topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto& adjNode : adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) q.push(adjNode);
        }
    }
    if(topo.size() != n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto& x : topo) cout << x << " ";
        cout << endl;
    }

    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}