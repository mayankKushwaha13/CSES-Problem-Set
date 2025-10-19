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

    //     ifstream testcase("../tests/Sorting and Searching/sum_of_two_values_tests/3.in");
    // ifstream testout("../tests/Sorting and Searching/sum_of_two_values_tests/3.out");

    int n, x;
    cin >> n >> x;
    vector<pii> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(), a.end());

    int i = 0;
    int j = n - 1;
    int ans1 = -1;
    int ans2 = -1;
    while (i < j)
    {
        int sum = a[i].fi + a[j].fi;
        if (sum == x)
        {
            ans1 = a[i].se + 1;
            ans2 = a[j].se + 1;
            break;
        }
        else if (sum > x)
        {
            j--;
        }
        else
            i++;
    }
    // string output;
    // getline(testout, output);
    string ans = to_string(ans1) + " " + to_string(ans2);
    if (ans1 == -1)
        ans = "IMPOSSIBLE";
    cout << ans << endl;
    // cout << output << endl;
    // ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}