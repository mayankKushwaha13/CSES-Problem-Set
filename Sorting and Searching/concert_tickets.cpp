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

// ifstream testcase("../tests/Sorting and Searching/concert_tickets_tests/5.in");
// ifstream testout("../tests/Sorting and Searching/concert_tickets_tests/5.out");

int n, m;
cin >> n >> m;
vi t(m);
unordered_map<int,int> freq;
multiset<int> h;
rep(i,0,n){ int x; cin >> x; h.insert(x); }
rep(i,0,m) cin >> t[i];

rep(i,0,m){
    int output = 0;
    // testout >> output;
    auto pos = h.upper_bound(t[i]); // strictly greater
    if(pos != h.begin()){
        pos--; // just behind
        cout << *pos << endl;
        h.erase(pos); // erase that one element
    }
    else{
        cout << -1 << endl;
    }
}
// cout << output << endl;
// ans == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}