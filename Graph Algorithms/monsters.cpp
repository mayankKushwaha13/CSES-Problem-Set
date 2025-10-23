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

    // ifstream testcase("../tests/Graph Algorithms/monsters_tests/1.in");
    // ifstream testout("../tests/Graph Algorithms/monsters_tests/1.out");
    int n, m;
    cin >> n >> m;

    vector<vector<char>> adj(n, vector<char>(m));
    vector<vi> direction(n, vi(m, -1));
    int drow[] = {0,0,1,-1};
    int dcol[] = {1,-1,0,0};
    vector<vi> dM(n, vi(m, INT_MAX)), dP(n, vi(m, INT_MAX));
    pii p;
    queue<pii> q;
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> adj[i][j];
            if(adj[i][j] == 'M'){
                q.push({i,j});
                dM[i][j] = 0;
            }
            if(adj[i][j] == 'A'){
                p.fi = i;
                p.se = j;
                dP[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int r = q.front().fi;
        int c = q.front().se;
        q.pop();
        rep(i,0,4){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && adj[nrow][ncol] == '.' && dM[nrow][ncol] > dM[r][c] + 1){
                dM[nrow][ncol] = dM[r][c] + 1;
                q.push({nrow, ncol});
            }
        }
    }
    q.push({p.fi, p.se});
    while(!q.empty()){
        int r = q.front().fi;
        int c = q.front().se;
        q.pop();
        rep(i,0,4){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && adj[nrow][ncol] == '.' && dP[nrow][ncol] > dP[r][c] + 1){
                dP[nrow][ncol] = dP[r][c] + 1;
                direction[nrow][ncol] = i;
                q.push({nrow, ncol});
            }
        }
    }
    int closest = INT_MAX;
    pii out = {-1,-1};
    rep(i,0,n){
        if((adj[i][0] = '.' || adj[i][0] == 'A') && dP[i][0] < dM[i][0] && dP[i][0] < closest){
            closest = dP[i][0];
            out.fi = i;
            out.se = 0;
        }
        if((adj[i][m-1] == '.' || adj[i][m - 1] == 'A') && dP[i][m-1] < dM[i][m - 1] && dP[i][m-1] < closest){
            closest = dP[i][m-1];
            out.fi = i;
            out.se = m - 1;
        }
    }
    rep(i, 0, m){
        if((adj[0][i] == '.' || adj[0][i] == 'A') && dP[0][i] < dM[0][i] && dP[0][i] < closest){
            closest = dP[0][i];
            out.fi = 0;
            out.se = i;
        }
        if((adj[n - 1][i] == '.' || adj[n - 1][i] == 'A') && dP[n - 1][i] < dM[n - 1][i] && dP[n - 1][i] < closest){
            closest = dP[n - 1][i];
            out.fi = n - 1;
            out.se = i;
        }
    }
    if (closest == INT_MAX) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl << closest << endl;

		string res = "", convert = "RLDU";
		while (out.fi != p.fi || out.se != p.se) {
			int idx = direction[out.fi][out.se];
			res += convert[idx];
			out.fi -= drow[idx];
			out.se -= dcol[idx];
		}

		reverse(res.begin(), res.end());
		cout << res << endl;
	}

    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}