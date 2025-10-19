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

// ifstream testcase("../tests/Sorting and Searching/restaurant_customers_tests/10.in");
// ifstream testout("../tests/Sorting and Searching/restaurant_customers_tests/10.out");

int n;
cin >> n;

vi a(n), b(n);
rep(i, 0, n){
    cin >> a[i] >> b[i];
}
sort(a.begin(), a.end());
sort(b.begin(), b.end());

int person = 0;
int ans = 1;
int j = 0;
rep(i,0,n){
    if(a[i] <= b[j]){
        person++;
    }
    else{
        j++;
    }
    ans = max(ans, person);
}
// int output;
// testout >> output;
cout << person << endl;
// cout << output << endl;
// person == output ? cout << "Success!" : cout << "Didn't match" << endl;
    return 0;
}