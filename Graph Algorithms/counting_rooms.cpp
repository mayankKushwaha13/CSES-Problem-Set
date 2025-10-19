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

int drow[] = {0, 0, 1, -1};
int dcol[] = {1, -1, 0, 0};
void dfs(vector<vector<char>> &adjMatrix, vector<vector<int>> &visited, int r, int c)
{
    visited[r][c] = 1;
    stack<pii> st;
    st.push({r, c});
    while (!st.empty())
    {
        int row = st.top().fi;
        int col = st.top().se;
        st.pop();
        rep(i, 0, 4)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < adjMatrix.size() && ncol < adjMatrix[0].size() && nrow >= 0 && ncol >= 0 && !visited[nrow][ncol] && adjMatrix[nrow][ncol] == '.')
            {
                visited[nrow][ncol] = 1;
                st.push({nrow,ncol});
            }
        }
    }
}
int main()
{
    fastio

    // ifstream testcase("../tests/Graph Algorithms/counting_rooms_tests/9.in");
    // ifstream testout("../tests/Graph Algorithms/counting_rooms_tests/9.out");

    int ans = 0;

    int n, m;
    cin >> n >> m;
    vector<vector<char>> adjMatrix(n, vector<char>(m));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> adjMatrix[i][j];
        }
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (adjMatrix[i][j] == '.' && !visited[i][j])
            {
                dfs(adjMatrix, visited, i, j);
                ans++;
            }
        }
    }
    // int output;
    // testout >> output;
    cout << ans << endl;
    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}