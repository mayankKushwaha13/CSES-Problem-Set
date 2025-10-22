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

    // ifstream testcase("../tests/Graph Algorithms/shortest_routes_i_tests/7.in");
    // ifstream testout("../tests/Graph Algorithms/shortest_routes_i_tests/7.out");
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    rep(i, 0, m){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    vector<long long> dist(n + 1, (1LL<<61));
    dist[1] = 0;
    pq.push({0LL,1});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        ll dis = cur.fi;
        int node = cur.se;
        if (dis != dist[node]) continue; 
        for(auto& p : adj[node]){
            int adjNode = p.fi;
            int edgeweight = p.se;
            if (dist[adjNode] > dis + (ll)edgeweight){
                dist[adjNode] = dis + (ll)edgeweight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    rep(i, 1, n + 1){
        cout << dist[i] << " " ;
    }
    cout << endl;
    // long long output;
    // bool okay = true;
    // rep(i,1,n+1){
    //     testout >> output;
    //     if(output != dist[i]){
    //         cout << output << " " << dist[i] << endl;
    //         okay = false;
    //         break;
    //     }
    // }
    // if(okay) cout << "SUCCESS!" << endl;
    // else cout << "Didn't Match." << endl; 
    return 0;
}