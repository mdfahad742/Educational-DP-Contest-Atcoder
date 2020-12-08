//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define ll                                      long long
#define pb                                      push_back
#define pf                                      push_front
#define eb                                      emplace_back
#define mp                                      make_pair
#define ff                                      first
#define ss                                      second
#define db                                      long double
#define pll                                     pair<ll, ll>
#define ALL(a)                                  (a).begin(),(a).end()
#define endl                                    "\n"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define ford1(i, n) for (int i = int(n) - 1; i >= 1; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define forabd(i, a, b) for(int i = int(a); i >= int(b); i--)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0)

/// ---------------------------- (Debug) ------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cout << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
	~debug() { cout << endl; }
	eni( != ) cout << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
	sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/// --------------------------------------------------------------------


const ll sz = 1e4 + 5;
const ll mod = 1e9 + 7;
const db PI = acos(-1);
const db eps = 1e-10;
const ll INF = 1e18 + 5;


typedef vector<ll> VL;
typedef vector<pll > VLL;
typedef vector<vector<ll> > VVL;
typedef vector<vector<vector<ll> > > VVVL;


ll power(ll n, ll k, ll m) {
	ll ans = 1;
	while (k) {
		if (k & 1) {
			ans = (ans * n) % m;
			k--;
		}
		else {
			n = (n * n) % m;
			k /= 2;
		}
	}
	return ans;
}
string k;
ll d;

ll dp[sz][101][2];

// standard dp on digits.

ll md(ll pos, ll sum, ll tight) {
	if (pos == (ll)k.size()) {
		if (sum == 0)
			return 1;
		return 0;
	}
	if (dp[pos][sum][tight] != -1)return dp[pos][sum][tight];
	ll ub = 9;
	if (tight) {
		ub = k[pos] - '0';
	}
	ll ans = 0;
	for (ll i = 0; i <= ub; i++) {
		ans += md(pos + 1, (sum + i) % d, tight && (ub == i));
		ans %= mod;
	}
	return dp[pos][sum][tight] = ans;
}

void solver() {
	cin >> k;
	cin >> d;
	memset(dp, -1, sizeof dp);
	cout << (((md(0, 0, 1) - 1) % mod) + mod) % mod  << endl;
}

int main() {

	IOS;
	ll T = 1; //cin >> T;
	forn1(i, T + 1) {
		//cout<<"Case #"<<i<<": ";
		solver();
	}
	return 0;
}
