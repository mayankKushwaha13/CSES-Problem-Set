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
    // ifstream testcase("../tests/Graph Algorithms/labyrinth_tests/13.in");
    // ifstream testout("../tests/Graph Algorithms/labyrinth_tests/13.out");
    string ans = "";
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adjMat(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, 1e6));
    pii start = {0, 0}, end = {n - 1, m - 1};
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> adjMat[i][j];
            if (adjMat[i][j] == 'A')
                start = {i, j};
            else if (adjMat[i][j] == 'B')
                end = {i, j};
        }
    }
    queue<pii> q;
    q.push(start);
    dist[start.fi][start.se] = 0;
    int drow[] = {0, 0, 1, -1};
    int dcol[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        pii curr = q.front();
        q.pop();
        rep(i, 0, 4)
        {
            int nrow = curr.fi + drow[i];
            int ncol = curr.se + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
            {
                if (adjMat[nrow][ncol] == '.')
                {
                    if (dist[curr.fi][curr.se] + 1 < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = dist[curr.fi][curr.se] + 1;
                        q.push({nrow, ncol});
                    }
                }
                else if (adjMat[nrow][ncol] == 'B')
                {
                    dist[nrow][ncol] = min(dist[nrow][ncol], dist[curr.fi][curr.se] + 1);
                }
            }
        }
    }
    if (dist[end.fi][end.se] == 1e6)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        cout << "YES" << endl;
        cout << dist[end.fi][end.se] << endl;
        ans = "";
        q.push(end);
        while (!q.empty())
        {
            pii curr = q.front();
            q.pop();
            rep(i, 0, 4)
            {
                int nrow = curr.fi + drow[i];
                int ncol = curr.se + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
                {
                    if (dist[nrow][ncol] != 1e6 && dist[nrow][ncol] == dist[curr.fi][curr.se] - 1)
                    {
                        q.push({nrow,ncol});
                        if(drow[i] == 1 && dcol[i] == 0){
                            ans += "U";
                        }
                        else if (drow[i] == -1 && dcol[i] == 0){
                            ans += "D";
                        }
                        else if (drow[i] == 0 && dcol[i] == 1){
                            ans += "L";
                        }
                        else{
                            ans += "R";
                        }
                        break;
                    }
                    // else if (adjMat[nrow][ncol] == 'A')
                    // {
                    //     dist[nrow][ncol] = min(dist[nrow][ncol], dist[curr.fi][curr.se] + 1);
                    // }
                }
            }
        }
    }

    // string output;
    // testout >> output;
    // if (output == "YES")
    // {
    //     testout >> output;
    //     testout >> output;
    // }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}