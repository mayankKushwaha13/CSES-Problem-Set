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

bool comp(pii a, pii b)
{
    return a.se < b.se;
}
int main()
{
    fastio

    //     ifstream testcase("../tests/Sorting and Searching/movie_festival_tests/11.in");
    // ifstream testout("../tests/Sorting and Searching/movie_festival_tests/11.out");

    int n;
    cin >> n;
    vector<pii> a(n);
    rep(i, 0, n) cin >> a[i].fi >> a[i].se;
    sort(a.begin(), a.end(), comp);

    int movies = 1;
    pii curr = a[0];
    rep(i, 0, n - 1)
    {
        pii next = a[i + 1];

        if (curr.se <= next.fi)
        {
            movies++;
            curr = next;
        }
    }
    // int output;
    // testout >> output;
    cout << movies << endl;
    // cout << output << endl;
    // movies == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}