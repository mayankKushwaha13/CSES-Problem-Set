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

    // ifstream testcase("../tests/Sorting and Searching/apartments_tests/19.in");
    // ifstream testoutput("../tests/Sorting and Searching/apartments_tests/19.out");
    // if (!testcase.is_open()){
    //     cout << "File failed to open" << endl;
    //     return 0;
    // }
    // int n, m, k;
    // testcase >> n >> m >> k;
    // int output;
    // testoutput >> output;

    int n,
    m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int index = 0;
    for (int i = 0; i < m;)
    {
        if (index >= n)
            break;
        if (a[index] >= b[i] - k && a[index] <= b[i] + k)
        {
            ans++;
            index++;
            i++;
        }
        else if (a[index] > b[i] + k)
        {
            i++;
        }
        else if (a[index] < b[i] - k)
        {
            index++;
        }
    }
    cout << ans << endl;
    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;

    return 0;
}