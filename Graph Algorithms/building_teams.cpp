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

int main()
{
    fastio

    //     ifstream testcase("../tests/Graph Algorithms/building_teams_tests/12.in");
    // ifstream testout("../tests/Graph Algorithms/building_teams_tests/12.out");

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<pii> edges;
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }
    vi teams(n + 1, -1);
    queue<int> q;
    rep(i, 1, n + 1)
    {
        if (teams[i] == -1)
        {
            teams[i] = 0;
            q.push(i);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (auto &v : adj[u])
                {
                    if (teams[v] == -1)
                    {
                        teams[v] = 1 - teams[u];
                        q.push(v);
                    }
                    else if (teams[v] == teams[u])
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        if (teams[u] == teams[v]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    rep(i, 1, n + 1) cout << teams[i] + 1 << " ";
    cout << endl;

    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}