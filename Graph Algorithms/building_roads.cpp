#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void dfs(vector<vi> &adj, vi &visited, int s)
{
    stack<int> st;
    st.push(s);
    visited[s] = 1;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        for (auto &v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                st.push(v);
            }
        }
    }
}
int main()
{
    fastio

    // ifstream testcase("../tests/Graph Algorithms/building_roads_tests/12.in");
    // ifstream testout("../tests/Graph Algorithms/building_roads_tests/12.out");
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vi visited(n + 1);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int disconnected = 0;
    vector<pii> edges;
    int prev = -1;
    rep(i, 1, n + 1)
    {
        if (!visited[i])
        {
            disconnected++;
            if (prev != -1)
                edges.push_back({prev, i});
            prev = i;
            dfs(adj, visited, i);
        }
    }
    cout << disconnected - 1 << endl;
    for (auto &p : edges)
    {
        cout << p.fi << " " << p.se << endl;
    }

    return 0;
}